// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Obstacle.h"
#include "RemovingObstacle.generated.h"

/**
 * 
 */
UCLASS()
class SCC_UE_HW06_API ARemovingObstacle : public AObstacle
{
	GENERATED_BODY()
	
public:
	ARemovingObstacle();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Obstacle|Property")
	float FlipTime;

	FTimerHandle RemovingObstacleTimerHandle;

protected:
	virtual void BeginPlay() override;

private:
	void FlipVisibility();
};
