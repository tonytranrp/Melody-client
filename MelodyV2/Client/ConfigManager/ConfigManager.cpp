#include "ConfigManager.h"
#include "../../Client/Client.h"

void ConfigManager::saveConfig() {
	std::string path = Utils::getClientPath() + "Configs\\";
	if (!std::filesystem::exists(path))
		std::filesystem::create_directory(path.c_str());
	client->moduleMgr->onSaveConfig(&currentConfigObj);

	std::string prefix = "A";
	prefix[0] = client->commandMgr->prefix;
	currentConfigObj["prefix"] = prefix;

	std::string fullPath = path + currentConfig + ".txt";
	std::ofstream o(fullPath, std::ifstream::binary);
	o << std::setw(4) << currentConfigObj << std::endl;
	o.flush();
	o.close();

}

void ConfigManager::loadConfig(std::string configName) {
	std::string path = Utils::getClientPath() + "Configs\\" + configName + ".txt";
	const bool configExists = std::filesystem::exists(path);
	if (configExists) {
		if (strcmp(configName.c_str(), currentConfig.c_str()) != 0)
			saveConfig();

		currentConfig = configName;
		std::ifstream confFile(path, std::ifstream::binary);
		json conf;
		currentConfigObj.clear();
		confFile >> currentConfigObj;
		client->moduleMgr->onLoadConfig(&currentConfigObj);
		if (currentConfigObj.contains("prefix")) {
			std::string prefix = currentConfigObj["prefix"];
			client->commandMgr->prefix = prefix.at(0);
		}
	}
}