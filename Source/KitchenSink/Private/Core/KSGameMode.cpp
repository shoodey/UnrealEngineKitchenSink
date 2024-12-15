// Copyright Shoodey. All Rights Reserved.

#include "KitchenSink/Public/Core/KSGameMode.h"
#include "KitchenSink/Public/Characters/KSPlayerCharacter.h"
#include "KitchenSink/Public/Core/KSPlayerController.h"
#include "Logger/KSLogger.h"

AKSGameMode::AKSGameMode()
{
	SetupDefaultPawnClass();
	SetupPlayerControllerClass();
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
