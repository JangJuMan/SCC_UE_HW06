// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingObstacle.h"

AMovingObstacle::AMovingObstacle() 
	: MoveSpeed(200.0f), MaxRange(1000.0f),
	StartLocation(FVector::Zero()), MoveDirection(1)
{
	PrimaryActorTick.bCanEverTick = true;
}

void AMovingObstacle::BeginPlay()
{
	Super::BeginPlay();
	StartLocation = GetActorLocation();
}

void AMovingObstacle::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	MoveObstacle(DeltaTime);
}

/* Tick 함수 기반 동적 Transform 변경*/
void AMovingObstacle::MoveObstacle(float DeltaTime)
{
	float DeltaMove = MoveSpeed * DeltaTime * MoveDirection;
	AddActorLocalOffset(FVector(DeltaMove, 0.0f, 0.0f));
	FVector NewLocation = GetActorLocation();

	float DistanceMoved = (NewLocation - StartLocation).Size();
	if (DistanceMoved > MaxRange)
	{
		MoveDirection *= -1;
		StartLocation = NewLocation;
	}
}

