// Copyright Shoodey. All Rights Reserved.

#include "KitchenSink/Public/Core/KSGameMode.h"
#include "KitchenSink/Public/Characters/KSPlayerCharacter.h"
#include "KitchenSink/Public/Core/KSPlayerController.h"

AKSGameMode::AKSGameMode()
{
	SetupDefaultPawnClass();
	SetupPlayerControllerClass();
}

void AKSGameMode::SetupDefaultPawnClass()
{
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(
		TEXT("/Game/KitchenSink/Characters/BP_PlayerCharacter"));

	if (PlayerPawnBPClass.Class != nullptr)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
	else
	{
		DefaultPawnClass = AKSPlayerCharacter::StaticClass();
	}

	UE_LOG(LogTemp, Log, TEXT("DefaultPawnClass: %s"), *PlayerPawnBPClass.Class->GetName());
}

void AKSGameMode::SetupPlayerControllerClass()
{
	static ConstructorHelpers::FClassFinder<APlayerController> PlayerControllerBPClass(
		TEXT("/Game/KitchenSink/Core/Input/PC_KitchenSink"));

	if (PlayerControllerBPClass.Class != nullptr)
	{
		PlayerControllerClass = PlayerControllerBPClass.Class;
	}
	else
	{
		PlayerControllerClass = AKSPlayerController::StaticClass();
	}
	
	UE_LOG(LogTemp, Log, TEXT("PlayerControllerClass: %s"), *PlayerControllerBPClass.Class->GetName());
}
