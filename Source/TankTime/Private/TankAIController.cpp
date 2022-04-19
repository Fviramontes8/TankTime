// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"




ATank* ATankAIController::GetAITank() const 
{
	return Cast<ATank>(GetPawn());
}

ATank* ATankAIController::GetPlayerTank() const
{
	return Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
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
		UE_LOG(LogTemp, Warning, TEXT("Found AI tank: %s"), *(ControlledTank->GetName()))
	}

	ATank* PlayerTank = GetPlayerTank();
	if (!PlayerTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("Could not find player tank"))
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("The player tank has been found! Their name: %s"), *(PlayerTank->GetName()))
	}
}
