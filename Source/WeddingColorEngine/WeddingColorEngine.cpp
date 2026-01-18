// Copyright Epic Games, Inc. All Rights Reserved.

#include "WeddingColorEngine.h"
#include "Modules/ModuleManager.h"
#include "Interfaces/IPluginManager.h"
#include "Misc/Paths.h"
#include "RenderCore.h"
#include "ShaderCore.h"

// Define class that inheits from the default implementation
class FWeddingColorEngineModule : public FDefaultGameModuleImpl
{
public: 
	virtual void StartupModule() override
	{
		// Map the virtual path "/Project" to physical /Shaders
	//	FString ShaderDir = FPaths::Combine(FPaths::ProjectDir(), TEXT("Shaders"));
	//	AddShaderSourceDirectoryMapping(TEXT("/Project"), ShaderDir);

		// Construct the physical path:
		FString ShaderDirectory = FPaths::Combine(FPaths::ProjectDir(), TEXT("Shaders"));

		// Define unique virtual path for this proj: 
		FString VirtualPath = TEXT("/WeddingColorEngine");

		// Safely map it
		if (!AllShaderSourceDirectoryMappings().Contains(VirtualPath))
		{
			AddShaderSourceDirectoryMapping(VirtualPath, ShaderDirectory);
		}
	}

	virtual void ShutdownModule() override
	{
		// cleanup logic 
	}
};
// Keeps default startup behavior but hooks the custom material path into it 
IMPLEMENT_PRIMARY_GAME_MODULE( FWeddingColorEngineModule, WeddingColorEngine, "WeddingColorEngine" );


