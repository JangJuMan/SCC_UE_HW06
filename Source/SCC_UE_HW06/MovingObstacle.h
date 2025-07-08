// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Obstacle.h"
#include "MovingObstacle.generated.h"

UCLASS()
class SCC_UE_HW06_API AMovingObstacle : public AObstacle
{
	GENERATED_BODY()
	
public:	
	AMovingObstacle();

	/**
	* member Variable
	*/
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Platform Settings")
	float MoveSpeed;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Platform Settings")
	float MaxRange;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Platform Settings")
	FVector StartLocation;
	int32 MoveDirection;

protected:
	virtual void BeginPlay() override;
	//void UpdatePositionRotation() override;

public:	
	virtual void Tick(float DeltaTime) override;
	void MoveObstacle(float DeltaTime);

};
