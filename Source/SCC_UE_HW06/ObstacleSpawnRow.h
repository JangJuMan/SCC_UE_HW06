#pragma once

#include "CoreMinimal.h"
#include "ObstacleSpawnRow.generated.h"

USTRUCT(BlueprintType)
struct FObstacleSpawnRow : public FTableRowBase 
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FName ObstacleName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<AActor> ObstacleClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float SpawnChance;
};