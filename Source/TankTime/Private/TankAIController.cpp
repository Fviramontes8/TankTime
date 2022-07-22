// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"



/*
Will try to find all AI tanks that are spawned on the map
*/
ATank* ATankAIController::GetAITank() const 
{
	return Cast<ATank>(GetPawn());
}

/*
Will look for player tank in the current game instance
*/
ATank* ATankAIController::GetPlayerTank() const
{
	return Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
}

/*
If the current instance is an AI tank, it will log its instance details
Otherwise, if it is a player, it will log the player instance name
*/
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
