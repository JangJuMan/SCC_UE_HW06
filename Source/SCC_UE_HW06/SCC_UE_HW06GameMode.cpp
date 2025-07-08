// Copyright Epic Games, Inc. All Rights Reserved.

#include "SCC_UE_HW06GameMode.h"
#include "SCC_UE_HW06Character.h"
#include "UObject/ConstructorHelpers.h"
#include "MyGameStateBase.h"

ASCC_UE_HW06GameMode::ASCC_UE_HW06GameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}

	GameStateClass = AMyGameStateBase::StaticClass();	// MyGameStateBase 연동(랜덤 장애물 스폰)
}
