// Copyright Shoodey. All Rights Reserved.

#include "KitchenSink/Public/Characters/KSBaseCharacter.h"

AKSBaseCharacter::AKSBaseCharacter()
{
}

void AKSBaseCharacter::BeginPlay()
{
	Super::BeginPlay();
}

// Called to bind functionality to input
void AKSBaseCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}
