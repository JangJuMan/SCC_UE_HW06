// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class SCC_UE_HW06 : ModuleRules
{
	public SCC_UE_HW06(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput" });
	}
}
