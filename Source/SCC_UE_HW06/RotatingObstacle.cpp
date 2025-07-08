// Fill out your copyright notice in the Description page of Project Settings.


#include "RotatingObstacle.h"

ARotatingObstacle::ARotatingObstacle() : RotationSpeed(50.0f)
{
	PrimaryActorTick.bCanEverTick = true;
}

void ARotatingObstacle::BeginPlay()
{
	Super::BeginPlay();
}

void ARotatingObstacle::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	RotateObstacle(DeltaTime);
}

/* Tick 함수 기반 동적 Transform 변경*/
void ARotatingObstacle::RotateObstacle(float DeltaTime)
{
	FRotator DeltaRotation = FRotator(0.0f, RotationSpeed * DeltaTime, 0.0f);
	AddActorLocalRotation(DeltaRotation);
}

