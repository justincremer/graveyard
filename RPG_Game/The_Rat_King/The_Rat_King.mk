##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=The_Rat_King
ConfigurationName      :=Debug
WorkspacePath          :=C:/Users/jacre/Desktop/Main/Code/CodeLite/CPP_Practice_1
ProjectPath            :=C:/Users/jacre/Desktop/Main/Code/CodeLite/CPP_Practice_1/The_Rat_King
IntermediateDirectory  :=$(ConfigurationName)
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=jacre
Date                   :=12/05/2020
CodeLitePath           :="C:/Program Files/CodeLite"
LinkerName             :=C:/mingw-w64/mingw64/bin/g++.exe
SharedObjectLinkerName :=C:/mingw-w64/mingw64/bin/g++.exe -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.i
DebugSwitch            :=-g 
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputFile             :=$(IntermediateDirectory)/$(ProjectName)
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :="The_Rat_King.txt"
PCHCompileFlags        :=
MakeDirCommand         :=makedir
RcCmpOptions           := 
RcCompilerName         :=C:/mingw-w64/mingw64/bin/windres.exe
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := C:/mingw-w64/mingw64/bin/ar.exe rcu
CXX      := C:/mingw-w64/mingw64/bin/g++.exe
CC       := C:/mingw-w64/mingw64/bin/gcc.exe
CXXFLAGS :=  -g -O0 -Wall $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := C:/mingw-w64/mingw64/bin/as.exe


##
## User defined environment variables
##
CodeLiteDir:=C:\Program Files\CodeLite
Objects0=$(IntermediateDirectory)/GameEngine.cpp$(ObjectSuffix) $(IntermediateDirectory)/Enemy.cpp$(ObjectSuffix) $(IntermediateDirectory)/Player.cpp$(ObjectSuffix) $(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IntermediateDirectory)/Sprite.cpp$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@$(MakeDirCommand) "$(ConfigurationName)"


$(IntermediateDirectory)/.d:
	@$(MakeDirCommand) "$(ConfigurationName)"

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/GameEngine.cpp$(ObjectSuffix): GameEngine.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/GameEngine.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/GameEngine.cpp$(DependSuffix) -MM GameEngine.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/jacre/Desktop/Main/Code/CodeLite/CPP_Practice_1/The_Rat_King/GameEngine.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/GameEngine.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/GameEngine.cpp$(PreprocessSuffix): GameEngine.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/GameEngine.cpp$(PreprocessSuffix) GameEngine.cpp

$(IntermediateDirectory)/Enemy.cpp$(ObjectSuffix): Enemy.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Enemy.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Enemy.cpp$(DependSuffix) -MM Enemy.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/jacre/Desktop/Main/Code/CodeLite/CPP_Practice_1/The_Rat_King/Enemy.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Enemy.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Enemy.cpp$(PreprocessSuffix): Enemy.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Enemy.cpp$(PreprocessSuffix) Enemy.cpp

$(IntermediateDirectory)/Player.cpp$(ObjectSuffix): Player.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Player.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Player.cpp$(DependSuffix) -MM Player.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/jacre/Desktop/Main/Code/CodeLite/CPP_Practice_1/The_Rat_King/Player.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Player.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Player.cpp$(PreprocessSuffix): Player.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Player.cpp$(PreprocessSuffix) Player.cpp

$(IntermediateDirectory)/main.cpp$(ObjectSuffix): main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/main.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/main.cpp$(DependSuffix) -MM main.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/jacre/Desktop/Main/Code/CodeLite/CPP_Practice_1/The_Rat_King/main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/main.cpp$(PreprocessSuffix): main.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/main.cpp$(PreprocessSuffix) main.cpp

$(IntermediateDirectory)/Sprite.cpp$(ObjectSuffix): Sprite.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Sprite.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Sprite.cpp$(DependSuffix) -MM Sprite.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/jacre/Desktop/Main/Code/CodeLite/CPP_Practice_1/The_Rat_King/Sprite.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Sprite.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Sprite.cpp$(PreprocessSuffix): Sprite.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Sprite.cpp$(PreprocessSuffix) Sprite.cpp


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r $(ConfigurationName)/


