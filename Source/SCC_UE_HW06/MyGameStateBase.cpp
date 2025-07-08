// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameStateBase.h"
#include "Kismet/GameplayStatics.h"
#include "SpawnVolume.h"

AMyGameStateBase::AMyGameStateBase() : NumOfObstacleToSpawn(10)
{
}

void AMyGameStateBase::BeginPlay()
{
	Super::BeginPlay();
	StartLevel();
}

/* NumOfObstacleToSpawn 만큼 장애물 spawn */
void AMyGameStateBase::StartLevel()
{
	TArray<AActor*> FoundVolumes;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ASpawnVolume::StaticClass(), FoundVolumes);

	for (int32 i = 0; i < NumOfObstacleToSpawn; i++)
	{
		if (FoundVolumes.Num() > 0)
		{
			for (int32 j = 0; j < FoundVolumes.Num(); j++)
			{
				ASpawnVolume* SpawnVolume = Cast<ASpawnVolume>(FoundVolumes[j]);
				if (SpawnVolume)
				{
					SpawnVolume->SpawnRandomObstacle();
				}
			}
		}
	}
}
