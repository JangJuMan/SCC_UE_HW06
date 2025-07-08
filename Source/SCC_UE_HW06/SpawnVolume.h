// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SpawnVolume.generated.h"

class UBoxComponent;
struct FObstacleSpawnRow;

UCLASS()
class SCC_UE_HW06_API ASpawnVolume : public AActor
{
	GENERATED_BODY()
	
public:	
	ASpawnVolume();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Spawning")
	USceneComponent* Scene;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Spawning")
	UBoxComponent* SpawningBox;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Spawning")
	UDataTable* ObstacleDataTable;

	/**
	 * member Fuctions
	 */
	UFUNCTION(BlueprintCallable, Category="Spawning")
	FVector GetRandomPointInVolume() const;
	UFUNCTION(BlueprintCallable, Category="Spawning")
	FRotator GetRandomRotator() const;
	UFUNCTION(BlueprintCallable, Category="Spawning")
	void SpawnObstacle(TSubclassOf<AActor> ObstacleClass);
	UFUNCTION(BlueprintCallable, Category="Spawning")
	void SpawnRandomObstacle();
	FObstacleSpawnRow* GetRandomObstacle() const;

};
