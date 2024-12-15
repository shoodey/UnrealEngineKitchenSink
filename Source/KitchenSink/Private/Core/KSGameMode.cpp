// Copyright Shoodey. All Rights Reserved.

#include "Core/KSGameMode.h"
#include "Characters/KSPlayerCharacter.h"
#include "Core/KSPlayerController.h"
#include "GameFramework/HUD.h"
#include "Logger/KSLogger.h"
#include "UI/KSHUD.h"

AKSGameMode::AKSGameMode()
{
	// Set up the default classes for the game mode - These run on editor startup.
	SetupDefaultPawnClass();
	SetupPlayerControllerClass();
	SetupHUDClass();
}

void AKSGameMode::SetupDefaultPawnClass()
{
	const FString BlueprintClassPath = "/Game/KitchenSink/Characters/BP_PlayerCharacter.BP_PlayerCharacter_C";

	if (UClass* LoadedClass = StaticLoadClass(APawn::StaticClass(), nullptr, *BlueprintClassPath))
	{
		DefaultPawnClass = LoadedClass;
	}
	else
	{
		DefaultPawnClass = AKSPlayerCharacter::StaticClass();
	}

	KS_LOG(Warning, "AKSGameMode::DefaultPawnClass `{Name}`", *DefaultPawnClass->GetName());
}

void AKSGameMode::SetupPlayerControllerClass()
{
	const FString BlueprintClassPath = "/Game/KitchenSink/Core/Input/PC_KitchenSink.PC_KitchenSink_C";

	if (UClass* LoadedClass = StaticLoadClass(APlayerController::StaticClass(), nullptr, *BlueprintClassPath))
	{
		PlayerControllerClass = LoadedClass;
	}
	else
	{
		PlayerControllerClass = AKSPlayerController::StaticClass();
	}

	KS_LOG(Warning, "AKSGameMode::PlayerControllerClass `{Name}`", *PlayerControllerClass->GetName());
}

void AKSGameMode::SetupHUDClass()
{
	const FString BlueprintClassPath = "/Game/KitchenSink/UI/HUD_KitchenSink.HUD_KitchenSink_C";

	if (UClass* LoadedClass = StaticLoadClass(AHUD::StaticClass(), nullptr, *BlueprintClassPath))
	{
		HUDClass = LoadedClass;
	}
	else
	{
		HUDClass = AKSHUD::StaticClass();
	}

	KS_LOG(Warning, "AKSGameMode::HUDClass `{Name}`", *HUDClass->GetName());
}
