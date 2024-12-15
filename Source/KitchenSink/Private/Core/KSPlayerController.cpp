// Copyright Shoodey. All Rights Reserved.

#include "Core/KSPlayerController.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "Characters/KSPlayerCharacter.h"

void AKSPlayerController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);

	PlayerCharacter = Cast<AKSPlayerCharacter>(InPawn);
	checkf(PlayerCharacter, TEXT("AKSPlayerController::OnPossess - Pawn is not of type %s"), *AKSPlayerCharacter::StaticClass()->GetName());

	EnhancedInputComponent = Cast<UEnhancedInputComponent>(InputComponent);
	checkf(EnhancedInputComponent, TEXT("AKSPlayerController::OnPossess - Unable to get a reference to EnhancedInputComponent"));

	UEnhancedInputLocalPlayerSubsystem* InputSubsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
	checkf(InputSubsystem, TEXT("AKSPlayerController::OnPossess - Unable to get a reference to EnhancedInputLocalPlayerSubsystem"));

	checkf(InputMappingContext, TEXT("AKSPlayerController::OnPossess - InputMappingContext was not set"));
	InputSubsystem->ClearAllMappings();
	InputSubsystem->AddMappingContext(InputMappingContext, 0);

	if (LookAction)
		EnhancedInputComponent->BindAction(LookAction, ETriggerEvent::Triggered, this, &AKSPlayerController::HandleLook);

	if (MoveAction)
		EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AKSPlayerController::HandleMove);

	if (JumpAction)
		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Triggered, this, &AKSPlayerController::HandleJump);
}

void AKSPlayerController::OnUnPossess()
{
	EnhancedInputComponent->ClearActionBindings();

	Super::OnUnPossess();
}

void AKSPlayerController::HandleLook(const FInputActionValue& InputActionValue)
{
	const FVector2D LookVector = InputActionValue.Get<FVector2D>();

	AddYawInput(LookVector.X);
	AddPitchInput(LookVector.Y);
}

void AKSPlayerController::HandleMove(const FInputActionValue& InputActionValue)
{
	const FVector2D MovementVector = InputActionValue.Get<FVector2D>();

	PlayerCharacter->AddMovementInput(PlayerCharacter->GetActorForwardVector(), MovementVector.Y);
	PlayerCharacter->AddMovementInput(PlayerCharacter->GetActorRightVector(), MovementVector.X);
}

void AKSPlayerController::HandleJump()
{
	PlayerCharacter->Jump();
}
