#include "SpawnVolume.h"
#include "Components/BoxComponent.h"
#include "ObstacleSpawnRow.h"

ASpawnVolume::ASpawnVolume()
{
	PrimaryActorTick.bCanEverTick = false;

	Scene = CreateDefaultSubobject<USceneComponent>(TEXT("Scene"));
	SetRootComponent(Scene);

	SpawningBox = CreateDefaultSubobject<UBoxComponent>(TEXT("SpawningBox"));
	SpawningBox->SetupAttachment(Scene);
}

FVector ASpawnVolume::GetRandomPointInVolume() const
{
	FVector BoxExtent = SpawningBox->GetScaledBoxExtent();
	FVector BoxOrigin = SpawningBox->GetComponentLocation();

	return BoxOrigin + FVector(
		FMath::FRandRange(-BoxExtent.X, BoxExtent.X),
		FMath::FRandRange(-BoxExtent.Y, BoxExtent.Y),
		FMath::FRandRange(-BoxExtent.Z, BoxExtent.Z)
	);
}

FRotator ASpawnVolume::GetRandomRotator() const
{
	return FRotator(
		FMath::FRandRange(0.0f, 360.0f),
		FMath::FRandRange(0.0f, 360.0f),
		FMath::FRandRange(0.0f, 360.0f)
	);
}

void ASpawnVolume::SpawnObstacle(TSubclassOf<AActor> ObstacleClass)
{
	if (!ObstacleClass) return;

	GetWorld()->SpawnActor<AActor>(
		ObstacleClass,
		GetRandomPointInVolume(),
		GetRandomRotator()
	);
}

/* 도전2. Spawn Actor를 통해 장애믈 임의 위치/로테이터에 특정 수(MyGameStateBase) 만큼 생성*/
void ASpawnVolume::SpawnRandomObstacle()
{
	UE_LOG(LogTemp, Warning, TEXT("SpawnRandom Obstacle"));
	if (FObstacleSpawnRow* SelectedRow = GetRandomObstacle())
	{
		UE_LOG(LogTemp, Warning, TEXT("SpawnRandom Obstacle 2"));
		if (UClass* ActualClass = SelectedRow->ObstacleClass.Get())
		{
			UE_LOG(LogTemp, Warning, TEXT("SpawnRandom Obstacle 3"));
			SpawnObstacle(ActualClass);
		}
	}
}

FObstacleSpawnRow* ASpawnVolume::GetRandomObstacle() const
{
	if (!ObstacleDataTable) return nullptr;

	TArray<FObstacleSpawnRow*> AllRows;
	static const FString ContextString(TEXT("ObstacleSpawnContext"));
	ObstacleDataTable->GetAllRows(ContextString, AllRows);

	if (AllRows.IsEmpty()) return nullptr;

	float TotalChance = 0.0f;
	for (const FObstacleSpawnRow* Row : AllRows)
	{
		if (Row)
		{
			TotalChance += Row->SpawnChance;
		}
	}

	const float RandValue = FMath::FRandRange(0.0f, TotalChance);
	float AccumulateChance = 0.0f;

	for (FObstacleSpawnRow* Row : AllRows)
	{
		AccumulateChance += Row->SpawnChance;
		if (RandValue <= AccumulateChance)
		{
			return Row;
		}
	}
	return nullptr;
}
