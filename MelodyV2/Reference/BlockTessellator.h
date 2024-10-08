
class BlockTessellator { /* Size=0x432a8 */
  /* 0x0000 */ bool mRenderingExtra;
  /* 0x0001 */ bool mUseNormals;
  /* 0x0008 */ BlockSource* mRegion;
  /* 0x0010 */ TextureUVCoordinateSet mFixedTexture;
  /* 0x0070 */ bool mUseFixedTexture;
  /* 0x0071 */ bool mUseOccluder;
  /* 0x0072 */ bool _tmpUseRegion;
  /* 0x0073 */ bool mXFlipTexture;
  /* 0x0074 */ int32_t mRenderingLayer;
  /* 0x0078 */ bool mRenderingGUI;
  /* 0x0079 */ bool mUsePBRFormats;
  /* 0x007a */ bool mShouldEmitPointLights;
  /* 0x007b */ bool mUseFixedColor;
  /* 0x007c */ std::array<mce::Color,6> mFixedColors;
  /* 0x00dc */ bool mApplyAmbientOcclusion;
  /* 0x00e0 */ BakedBlockLightType mBakedLighting;
  /* 0x00e4 */ bool mForExport;
  /* 0x00e8 */ mce::Color mAoColors[8];
  /* 0x0168 */ BrightnessPair mTc[4];
  /* 0x0170 */ std::array<enum Flip,6> mFlipFace;
  /* 0x0188 */ std::array<BlockTessellator::UVOverride,6> mTextureOverride;
  /* 0x0200 */ const Block* mAmbientOcclusionCacheBlocks[125];
  /* 0x05e8 */ mce::MaterialPtr mItemMat;
  /* 0x05f8 */ AABB mCurrentShapeBB;
  /* 0x0614 */ bool mCurrentShapeSet;
  /* 0x0618 */ const Block* mCurrentShapeBlock;
  /* 0x0620 */ BlockPos mCurrentShapeBlockPos;
  /* 0x062c */ float mCurrentScale;
  /* 0x0630 */ std::unordered_map<unsigned int,mce::Mesh,std::hash<unsigned int>,std::equal_to<unsigned int>,std::allocator<std::pair<unsigned int const ,mce::Mesh> > > mBlockMeshes;
  /* 0x0670 */ std::unordered_map<BlockTessellatorBlockInWorld,mce::Mesh,std::hash<BlockTessellatorBlockInWorld>,std::equal_to<BlockTessellatorBlockInWorld>,std::allocator<std::pair<BlockTessellatorBlockInWorld const ,mce::Mesh> > > mInWorldBlockMeshes;
  /* 0x06b0 */ BlockTessellatorCache mBlockCache;
  /* 0x42d48 */ std::function<Block const & __cdecl(BlockPos const &)> mCachedGetBlock;
  /* 0x42d88 */ bool mForceOpaque;
  /* 0x42d90 */ std::vector<mce::PointLight,std::allocator<mce::PointLight> > mPointLights;
  /* 0x42da8 */ std::array<BlockTessellator::AocBlockFaceData,6> mAocBlockData;
  /* 0x43228 */ BlockTessellatorCustomExtraData::Map mBlockExtraDataMap;
  static const float TEXTURE_OFFSET;
  static const std::array<unsigned __int64,6> sAocAxisX;
  static const std::array<unsigned __int64,6> sAocAxisY;
  static const std::array<unsigned __int64,6> sAocAxisZ;
  
  BlockTessellator(BlockTessellator&);
  BlockTessellator(const BlockTessellator&);
  BlockTessellator(BlockSource*);
  void setRegion(BlockSource&);
  void resetRegion();
  BlockSource& getRegion() const;
  void setRenderLayer(int32_t);
  void setBakedLighting(BakedBlockLightType);
  void setForExport(bool);
  void setBlockExtraDataMap(BlockTessellatorCustomExtraData::Map);
  float getWaterHeight(const BlockPos&, const Material&, const BlockPos&);
  int32_t blend(int32_t, int32_t, int32_t, int32_t);
  bool isTranslucent(const Block&);
  bool isSolidRender(const Block&);
  void setForceOpaque(bool);
  void setUsePBRFormats(bool);
  void setShouldEmitPointLights(bool);
  mce::Mesh& getMeshForBlock(Tessellator&, const Block&);
  mce::Mesh& getMeshForBlockInWorld(Tessellator&, const Block&, BlockPos&, BlockRenderLayer, const void*, bool);
  int32_t getLightEmission(const Block&);
  bool tessellateInWorld(Tessellator&, const Block&, const BlockPos&, bool);
  void tessellateInWorld(Tessellator&, const Block&, const BlockPos&, const TextureUVCoordinateSet&);
  void tessellateSimpleBlockInWorld(Tessellator&, const Block&, const BlockPos&, const AirAndSimpleBlockBits&);
  BrightnessPair getLightColor(const BlockPos&);
  void appendTessellatedBlock(Tessellator&, const Block&);
  void renderGuiBlock(ScreenContext&, const Block&, const BlockGraphics&, const mce::TexturePtr&, float, float);
  void clearBlockCache();
  void resetCache(const BlockPos&);
  void resetCacheToAir(const BlockPos&);
  void updateCache(const Block&, const BlockPos&);
  bool tessellateStructureVoidInWorld(Tessellator&, const Block&, const BlockPos&);
  std::vector<mce::PointLight,std::allocator<mce::PointLight> >& movePointLights();
  bool tessellateBlockInWorld(Tessellator&, const Block&, const BlockPos&, const AirAndSimpleBlockBits*);
  bool tessellateBlockInWorldFlat(Tessellator&, const Block&, const BlockPos&, const mce::Color&, BlockOccluder*, int32_t);
  bool tessellateBlockInWorldWithAmbienceOcclusion(Tessellator&, const Block&, BlockPos, const mce::Color&, BlockOccluder*, int32_t);
  bool tessellateTrapdoorInWorld(Tessellator&, const Block&, const BlockPos&);
  bool tessellateExtraDataInWorld(Tessellator&, const Block&, const BlockPos&);
  bool tessellateCrossInWorld(Tessellator&, const Block&, const BlockPos&, bool);
  bool tessellateKelpInWorld(Tessellator&, const Block&, const BlockPos&);
  bool tessellateCoralFanInWorld(Tessellator&, const Block&, const BlockPos&);
  bool tessellateCoralFanHangInWorld(Tessellator&, const Block&, const BlockPos&);
  void tessellateCrossTexture(Tessellator&, const TextureUVCoordinateSet&, const TextureUVCoordinateSet&, const Vec3&, bool, const Block&, float);
  void tessellateCrossTexture(Tessellator&, const TextureUVCoordinateSet&, const Vec3&, bool, const Block&, float);
  bool tessellateLiquidInWorld(Tessellator&, const Block&, const BlockPos&);
  bool tessellateWallInWorld(Tessellator&, const Block&, const BlockPos&);
  bool tessellateRailInWorld(Tessellator&, const Block&, const BlockPos&);
  bool tessellateTopSnowInWorld(Tessellator&, const Block&, const BlockPos&);
  bool tessellateTorchInWorld(Tessellator&, const Block&, const BlockPos&);
  bool tessellateFireInWorld(Tessellator&, const Block&, BlockPos);
  bool tessellateLadderInWorld(Tessellator&, const Block&, const BlockPos&);
  bool tessellateCactusInWorld(Tessellator&, const Block&, const BlockPos&);
  bool tessellateDoublePlantInWorld(Tessellator&, const Block&, const BlockShape, const BlockPos&, bool);
  bool tessellateSeagrassInWorld(Tessellator&, const Block&, const BlockPos&);
  bool tessellateSeaPickleInWorld(Tessellator&, const Block&, const BlockPos&);
  bool tessellateIndividualSeaPickleInWorld(Tessellator&, const Block&, const Vec3&, const double, const Vec3);
  bool tessellateTurtleEggInWorld(Tessellator&, const Block&, const BlockPos&);
  bool tessellateIndividualTurtleEggInWorld(Tessellator&, const Block&, const Vec3&, const Vec3, const Vec3, const int32_t);
  bool tessellateStemInWorld(Tessellator&, const Block&, const BlockPos&);
  bool tessellateStairsInWorld(Tessellator&, const Block&, const BlockPos&);
  bool tessellateDoorInWorld(Tessellator&, const Block&, const BlockPos&);
  bool tessellateFenceInWorld(Tessellator&, const Block&, const BlockPos&);
  bool tessellateDoubleThinFenceInWorld(Tessellator&, const Block&, const BlockPos&, bool);
  bool tessellateFenceGateInWorld(Tessellator&, const Block&, const BlockPos&);
  bool tessellateRowInWorld(Tessellator&, const Block&, const BlockPos&, bool);
  bool tessellateVineInWorld(Tessellator&, const Block&, const BlockPos&);
  bool tessellateWeepingVinesInWorld(Tessellator&, const Block&, const BlockPos&);
  bool tessellateTwistingVinesInWorld(Tessellator&, const Block&, const BlockPos&);
  bool tessellateChainInWorld(Tessellator&, const Block&, const BlockPos&);
  bool tessellateCocoaInWorld(Tessellator&, const Block&, const BlockPos&);
  bool tessellateEndPortalFrameInWorld(Tessellator&, const Block&, const BlockPos&);
  bool tessellateTreeInWorld(Tessellator&, const Block&, const BlockPos&);
  void tessellateTorch(Tessellator&, const Block&, const Vec3&, float, float, float);
  void tessellateStemTexture(Tessellator&, const TextureUVCoordinateSet&, float, float, float, float);
  void tessellateStemDirTexture(Tessellator&, const TextureUVCoordinateSet&, int32_t, float, const Vec3&);
  void tessellateRowTexture(Tessellator&, const TextureUVCoordinateSet&, const TextureUVCoordinateSet&, const TextureUVCoordinateSet&, const TextureUVCoordinateSet&, float, float, float);
  void tessellateRowTexture(Tessellator&, const Block&, const BlockPos&, const TextureUVCoordinateSet&, float, float, float, bool);
  bool tessellateFlowerPotInWorld(Tessellator&, const Block&, const BlockPos&);
  bool tessellateAnvilInWorld(Tessellator&, const Block&, const BlockPos&, bool);
  bool tessellateBrewingStandInWorld(Tessellator&, const Block&, const BlockPos&);
  bool tessellateLilypadInWorld(Tessellator&, const Block&, const BlockPos&);
  float tessellateAnvilPiece(Tessellator&, const Block&, const BlockPos&, AnvilPart, float, float, float, float, bool, bool, buffer_span<enum Flip>);
  bool tessellateLeverInWorld(Tessellator&, const Block&, const BlockPos&);
  bool tessellateDustInWorld(Tessellator&, const Block&, const BlockPos&);
  bool tessellateTripwireHookInWorld(Tessellator&, const Block&, const BlockPos&);
  bool tessellateTripwireInWorld(Tessellator&, const Block&, const BlockPos&);
  bool tessellateCauldronInWorld(Tessellator&, const Block&, const BlockPos&);
  bool tessellateRepeaterInWorld(Tessellator&, const Block&, const BlockPos&);
  bool tessellateComparatorInWorld(Tessellator&, const Block&, const BlockPos&);
  bool tessellateDiodeInWorld(Tessellator&, const Block&, const BlockPos&);
  bool tessellateHopperInWorld(Tessellator&, const Block&, const BlockPos&, bool);
  bool tessellateHopperInWorld(Tessellator&, const Block&, const BlockPos&);
  bool tessellateSlimeBlockInWorld(Tessellator&, const Block&, const BlockPos&);
  bool tessellateHoneyBlockInWorld(Tessellator&, const Block&, const BlockPos&);
  bool tessellatePistonInWorld(Tessellator&, const Block&, const BlockPos&);
  bool tessellateBarrierBlockInWorld(Tessellator&, const Block&, const BlockPos&);
  bool tessellateBeaconInWorld(Tessellator&, const Block&, const BlockPos&);
  void tessellateBeacon(Tessellator&, const Block&, float, const float, const Vec3&);
  bool tessellateDragonEgg(Tessellator&, const Block&, const BlockPos&, bool, int32_t);
  bool tessellateChorusFlowerInWorld(Tessellator&, const Block&, const BlockPos&, bool);
  bool tessellateChorusPlantInWorld(Tessellator&, const Block&, const BlockPos&);
  bool tessellateEndPortalInWorld(Tessellator&, const Block&, const BlockPos&);
  bool tessellateEndGatewayInWorld(Tessellator&, const Block&, const BlockPos&);
  bool tessellateEndRodInWorld(Tessellator&, const Block&, const BlockPos&);
  void tessellateEndRodUp(Tessellator&, const BlockPos&, const TextureUVCoordinateSet&);
  void tessellateEndRodDown(Tessellator&, const BlockPos&, const TextureUVCoordinateSet&);
  void tessellateEndRodNorth(Tessellator&, const BlockPos&, const TextureUVCoordinateSet&);
  void tessellateEndRodSouth(Tessellator&, const BlockPos&, const TextureUVCoordinateSet&);
  void tessellateEndRodWest(Tessellator&, const BlockPos&, const TextureUVCoordinateSet&);
  void tessellateEndRodEast(Tessellator&, const BlockPos&, const TextureUVCoordinateSet&);
  void tessellateEndRodAppended(Tessellator&, const Block&, const BlockGraphics&);
  void tessellateEndRodGui(Tessellator&, const Block&, const BlockGraphics&);
  bool tessellateFacingBlockInWorld(Tessellator&, const Block&, const BlockPos&);
  bool tessellateCommandBlockInWorld(Tessellator&, const Block&, const BlockPos&);
  bool rotateCommandBlockFaces(const Block&);
  void tessellateShulkerBoxFacade(Tessellator&, const Vec3&);
  bool tessellateTerracottaInWorld(Tessellator&, const Block&, const BlockPos&);
  bool tessellateItemFrameInWorld(Tessellator&, const Block&, const BlockPos&);
  bool tessellateChemistryTableInWorld(Tessellator&, const Block&, const BlockPos&);
  bool tessellateCompoundCreatorInWorld(Tessellator&, const Block&, const BlockPos&);
  void tessellateCompoundCreatorFace(Tessellator&, const Block&, const Vec3&, const TextureUVCoordinateSet&, Vec2, Vec2, const int32_t, bool, Matrix*);
  bool tessellateBubbleColumnInWorld(Tessellator&, const Block&, const BlockPos&);
  bool tessellateScaffoldingBlockInWorld(Tessellator&, const Block&, const BlockPos&);
  void tessellateScaffoldingVerticalPoleInWorld(Tessellator&, const Block&, const TextureUVCoordinateSet&, const BlockPos&, const Flip);
  void tessellateScaffoldingHorizontalPoleInWorld(Tessellator&, const Block&, const TextureUVCoordinateSet&, const TextureUVCoordinateSet&, const BlockPos&, Flip, const Vec3&, const bool);
  bool tessellateStoneCutterBlockInWorld(Tessellator&, const Block&, const BlockPos&);
  bool tessellateBambooBlockInWorld(Tessellator&, const Block&, const BlockPos&, bool);
  void tessellateBambooStemInWorld(Tessellator&, const Block&, const BlockPos&, const BlockGraphics&, const float, const float, const float);
  void tessellateBambooTopSideLeafInWorld(Tessellator&, const Vec3, const float, const float, const float, const float, const float, const bool);
  void tessellateBambooLargeLeafInWorld(Tessellator&, const TextureUVCoordinateSet&, const Vec3&, const float);
  void tessellateBambooSmallLeafInWorld(Tessellator&, const TextureUVCoordinateSet&, const Vec3&, const float);
  bool tessellateBambooSaplingInWorld(Tessellator&, const Block&, const BlockPos&);
  bool tessellateLanternBlockInWorld(Tessellator&, const Block&, const BlockPos&);
  bool tessellateGrindstoneBlockInWorld(Tessellator&, const Block&, const BlockPos&);
  void tessellateGrindstoneLegInWorld(Tessellator&, const Block&, const BlockPos&, bool, bool, Direction::Type);
  bool tessellateBellBlockInWorld(Tessellator&, const Block&, const BlockPos&);
  bool tessellateBellBlockHangingTopInWorld(Tessellator&, const Block&, const BlockPos&);
  bool tessellateBellBlockHangingBetweenInWorld(Tessellator&, const Block&, const BlockPos&, const bool, const Direction::Type);
  bool tessellateBellBlockHangingOneSideInWorld(Tessellator&, const Block&, const BlockPos&, const bool, const Direction::Type);
  bool tessellateBellBlockStandingInWorld(Tessellator&, const Block&, const BlockPos&, const bool, const Direction::Type);
  void tessellateBellBlockStandingLegInWorld(Tessellator&, const Block&, const BlockPos&, const BlockGraphics&, const bool);
  bool tessellateCampfireBlockInWorld(Tessellator&, const Block&, const BlockPos&);
  bool tessellateLecternBlockInWorld(Tessellator&, const Block&, const BlockPos&);
  bool tessellateSweetBerryBushBlockInWorld(Tessellator&, const Block&, const BlockPos&);
  bool tessellateComposterBlockInWorld(Tessellator&, const Block&, const BlockPos&);
  void renderTessellatedModel(Tessellator&, const Block&, const BlockPos&, const Vec3&, const std::vector<TextureUVCoordinateSet,std::allocator<TextureUVCoordinateSet> >&, const BlockGeometry::TessellatedModel&, Facing::Rotation);
  void prepareAndRenderTessellatedModel(Tessellator&, const BlockGraphics&, const Block&, const BlockPos&, const Vec3&, Facing::Rotation, int32_t);
  Facing::Rotation getRotationFromDir(int32_t);
  void tessellateFaceDown(Tessellator&, const Block&, const Vec3&, const TextureUVCoordinateSet&);
  void tessellateFaceUp(Tessellator&, const Block&, const Vec3&, const TextureUVCoordinateSet&);
  void tessellateNorth(Tessellator&, const Block&, const Vec3&, const TextureUVCoordinateSet&);
  void tessellateSouth(Tessellator&, const Block&, const Vec3&, const TextureUVCoordinateSet&);
  void tessellateWest(Tessellator&, const Block&, const Vec3&, const TextureUVCoordinateSet&);
  void tessellateEast(Tessellator&, const Block&, const Vec3&, const TextureUVCoordinateSet&);
  void tessellateAll(Tessellator&, const Block&, const Vec3&, const TextureUVCoordinateSet&);
  void tessellateFaceWithUVs(Tessellator&, const Block&, const Vec3&, const TextureUVCoordinateSet&, const float, const float, const float, const float, const int32_t);
  void tessellateVerticesAndUVs(Tessellator&, const TextureUVCoordinateSet&, const Vec3&, const Vec3&, Vec2&, Vec2&, Vec2&, Vec2&, const int32_t);
  void offsetUVs(const TextureUVCoordinateSet&, Vec2*, Vec2*, Vec2*, Vec2*);
  bool tessellateMicroBlockInWorld(Tessellator&, const Block&, const Vec3&);
  mce::Color _getBlockColor(const BlockPos&, const Block&);
  Vec3 _preparePolyCrossAndModifyPos(Tessellator&, const BlockPos&, const Block&);
  void _preparePolyCross(Tessellator&, const BlockPos&, const Block&);
  void _randomizeFaceDirection(const Block&, unsigned char, const BlockPos&, const TextureUVCoordinateSet&);
  Vec3 _rotateYAroundPivot(const Vec3&, const Vec3&, float) const;
  Vec3 _rotateBlockPos(const Vec3&, Facing::Rotation) const;
  Flip _flipForRotation(Flip, Facing::Rotation) const;
  unsigned char _faceForRotation(unsigned char, Facing::Rotation) const;
  void _flipAllFaces(Facing::Rotation);
  void _clearFlipFace();
  void _tessellateAllFaces(Tessellator&, const Block&, const BlockPos&);
  BrightnessPair _getLightColorForWater(const BlockPos&, BrightnessPair);
  const TextureUVCoordinateSet& _getMappedTexture(const Block&, unsigned char) const;
  const TextureUVCoordinateSet& _getTexture(const BlockPos&, const Block&, unsigned char, int32_t) const;
  void _tex1(Tessellator&, const Vec2&);
  void _setTextureOverrideWithTexture(const TextureUVCoordinateSet&);
  void _forceTextureOnFace(const Facing::Name, const TextureUVCoordinateSet&);
  void _prepareFixedColorsWithFlatAO(const Block&, const BlockPos&);
  void _pbrTextureId(Tessellator&, const uint16_t&) const;
  const AABB& getCurrentShape();
  void setCurrentShape(float, float, float, float, float, float);
  void setCurrentShape(const Vec3&, const Vec3&);
  void setCurrentShape(const AABB&);
  void setCurrentShapeFromExtents(const Vec3&, const Vec3&);
  void moveCurrentShape(const Vec3&);
  void unsetCurrentShape();
  void _setShapeAndTessellate(Tessellator&, const Vec3&, const Vec3&, const Block&, const BlockPos&);
  void _rotateVerts(const std::array<Vec3,4>&, std::array<Vec3,4>&, Facing::Rotation);
  void _rotateNormal(const Vec3&, Vec3&, Facing::Rotation);
  void _renderTessellatedAlignedFaces(Tessellator&, const Vec3&, const std::vector<TextureUVCoordinateSet,std::allocator<TextureUVCoordinateSet> >&, const std::vector<BlockGeometry::AlignedFace,std::allocator<BlockGeometry::AlignedFace> >&, const Facing::Rotation, const unsigned char);
  void _renderTessellatedAlignedFacesWithAO(Tessellator&, const Vec3&, const std::vector<TextureUVCoordinateSet,std::allocator<TextureUVCoordinateSet> >&, const std::vector<BlockGeometry::AlignedFace,std::allocator<BlockGeometry::AlignedFace> >&, const Facing::Rotation, const unsigned char);
  void _renderTessellatedOrientedFaces(Tessellator&, const Vec3&, const std::vector<TextureUVCoordinateSet,std::allocator<TextureUVCoordinateSet> >&, const std::vector<BlockGeometry::OrientedFace,std::allocator<BlockGeometry::OrientedFace> >&, const Facing::Rotation);
  void _renderTessellatedOrientedFacesWithAO(Tessellator&, const Vec3&, const std::vector<TextureUVCoordinateSet,std::allocator<TextureUVCoordinateSet> >&, const std::vector<BlockGeometry::OrientedFace,std::allocator<BlockGeometry::OrientedFace> >&, const Facing::Rotation);
  void _renderTessellatedModel(Tessellator&, const Block&, const BlockPos&, const Vec3&, const std::vector<TextureUVCoordinateSet,std::allocator<TextureUVCoordinateSet> >&, const BlockGeometry::TessellatedModel&, Facing::Rotation);
  void _generateAOCBlockData(const Block&, const BlockPos&, const Vec3&, std::array<BlockTessellator::AocBlockFaceData,6>&);
  void _renderModTessellatedModel(Tessellator&, const Block&, const BlockPos&, const Vec3&, const std::vector<TextureUVCoordinateSet,std::allocator<TextureUVCoordinateSet> >&, const Netease::ModBlockGeometry::BlockModel&, Facing::Rotation, bool);
  void _renderModTessellatedModelDFS(Tessellator&, const Block&, const BlockPos&, const Vec3&, const std::vector<TextureUVCoordinateSet,std::allocator<TextureUVCoordinateSet> >&, const Netease::ModBlockGeometry::BlockModel&, Facing::Rotation, RenderParams&, int32_t);
  void _renderModTessellatedModelDFSWithAO(Tessellator&, const Block&, const BlockPos&, const Vec3&, const std::vector<TextureUVCoordinateSet,std::allocator<TextureUVCoordinateSet> >&, const Netease::ModBlockGeometry::BlockModel&, Facing::Rotation, RenderParams&, int32_t);
  void _renderTessellatedOrientedFacesWithAOMod(Tessellator&, const Vec3&, const std::vector<TextureUVCoordinateSet,std::allocator<TextureUVCoordinateSet> >&, const std::vector<BlockGeometry::OrientedFace,std::allocator<BlockGeometry::OrientedFace> >&, const Facing::Rotation);
  void _tessellateMicroBox(Tessellator&, const Block&, const BlockPos&, const TextureUVCoordinateSet&, int32_t, const std::vector<std::shared_ptr<Netease::MicroBlockGeometry::MicroBlockRenderItem>,std::allocator<std::shared_ptr<Netease::MicroBlockGeometry::MicroBlockRenderItem> > >&);
  void _swapShapeAxes(const bool, const bool, const bool);
  void _modifyCurrentShapeAccordingToAttachmentDirection(Direction::Type);
  void _resetOverrides();
  bool _isRedstoneTorch(const Block&);
  bool _shouldUseSmoothLighting() const;
  void _tryAddPointLight(const BlockTessellator::PointLightType, const glm::tvec3<float,0>&);
  ~BlockTessellator();
  BlockTessellator& operator=(BlockTessellator&);
  BlockTessellator& operator=(const BlockTessellator&);
  void __autoclassinit2(uint64_t);
  void __dflt_ctor_closure();
  void* __vecDelDtor(uint32_t);
  
  static bool canRender(BlockShape);
  static bool isRenderAsTextureItem(const BlockLegacy&);
  static bool isRenderAsModelItem(const BlockLegacy&);
};
