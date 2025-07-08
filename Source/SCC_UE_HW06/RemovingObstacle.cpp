// Fill out your copyright notice in the Description page of Project Settings.


#include "RemovingObstacle.h"

ARemovingObstacle::ARemovingObstacle() : FlipTime(10.0f)
{

}

/* 도전 1번: 타이머 시스템 활용 시간 기반 발판이 사라지는 로직 */
void ARemovingObstacle::BeginPlay()
{
	Super::BeginPlay();

	GetWorldTimerManager().SetTimer(	// Flip Time 마다 FlipVisibility 반복 실행
		RemovingObstacleTimerHandle,
		this,
		&ARemovingObstacle::FlipVisibility,
		FlipTime,
		true
	);
}

/* Flip Time마다 장애물 On/Off */
void ARemovingObstacle::FlipVisibility()
{
	float CurrentTime = GetWorld()->GetTimeSeconds();
	UE_LOG(LogTemp, Warning, TEXT("Flip at %.2f seconds"), CurrentTime);

	bool bNewVisible = IsHidden();
	SetActorHiddenInGame(!bNewVisible);
	SetActorEnableCollision(bNewVisible);
	SetActorTickEnabled(bNewVisible);
}
