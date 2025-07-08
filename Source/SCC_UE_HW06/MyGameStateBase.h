// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "MyGameStateBase.generated.h"

/**
 * 
 */
UCLASS()
class SCC_UE_HW06_API AMyGameStateBase : public AGameStateBase
{
	GENERATED_BODY()

public:
	AMyGameStateBase();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawn")
	int32 NumOfObstacleToSpawn;

	virtual void BeginPlay() override;

	void StartLevel();
	
};
