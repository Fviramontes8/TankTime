// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"




ATank* ATankAIController::GetAITank() const 
{
	return Cast<ATank>(GetPawn());
}

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
	ATank* ControlledTank = GetAITank();
	if (!ControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("No AI tanks found..."))
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Found tank: %s"), *(ControlledTank->GetName()))
	}
}
