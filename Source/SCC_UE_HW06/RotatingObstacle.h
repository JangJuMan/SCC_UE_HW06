// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Obstacle.h"
#include "RotatingObstacle.generated.h"

UCLASS()
class SCC_UE_HW06_API ARotatingObstacle : public AObstacle
{
	GENERATED_BODY()
	
public:	
	ARotatingObstacle();

	/**
	* member Variable
	*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Platform Settings")
	float RotationSpeed;

protected:
	virtual void BeginPlay() override;
	//void UpdatePositionRotation() override;

public:	
	virtual void Tick(float DeltaTime) override;
	
	void RotateObstacle(float DeltaTime);

};
