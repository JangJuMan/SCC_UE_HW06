// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Obstacle.generated.h"

UCLASS()
class SCC_UE_HW06_API AObstacle : public AActor
{
	GENERATED_BODY()
	
public:	
	AObstacle();

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Obstacle|Component")
	USceneComponent* Scene;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Obstacle|Component")
	UStaticMeshComponent* StaticMesh;
};
