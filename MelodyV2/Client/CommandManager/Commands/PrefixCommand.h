// Created by Tony on 2024-10-10 10:01:54

#pragma once
#include <vector>
#include <string>
#include <algorithm>
class PrefixCommand {
public:
	std::string name;
	std::string description;
	std::vector<std::string> aliases;

	PrefixCommand(std::string commandName, std::string descr, std::vector<std::string> alias) {
		this->name = commandName;
		this->description = descr;
		this->aliases = alias;
		std::transform(commandName.begin(), commandName.end(), commandName.begin(), ::tolower);
		this->aliases.push_back(commandName);
	}

	virtual bool execute(const std::vector<std::string>& args);
};