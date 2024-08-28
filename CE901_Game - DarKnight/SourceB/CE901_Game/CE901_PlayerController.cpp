// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CE901_PlayerController.h"
#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "Engine/LocalPlayer.h"
#include "InputActionValue.h"


ACE901_PlayerController::ACE901_PlayerController()
{
    bShowMouseCursor = true;
    DefaultMouseCursor = EMouseCursor::Default;
}

void ACE901_PlayerController::BeginPlay()
{
    Super::BeginPlay();

    // Add Input Mapping Context
    if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
    {
        Subsystem->AddMappingContext(DefaultMappingContext, 0);
    }
}

void ACE901_PlayerController::SetupInputComponent()
{
    Super::SetupInputComponent();

    if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(InputComponent))
    {
        // Bind movement actions
        EnhancedInputComponent->BindAction(MoveForwardAction, ETriggerEvent::Triggered, this, &ACE901_PlayerController::MoveForward);
        EnhancedInputComponent->BindAction(MoveRightAction, ETriggerEvent::Triggered, this, &ACE901_PlayerController::MoveRight);
    }
}

void ACE901_PlayerController::MoveForward(const FInputActionValue& Value)
{
    ACharacter* MyCharacter = Cast<ACharacter>(GetPawn());
    if (MyCharacter)
    {
        FVector Direction = FRotationMatrix(MyCharacter->GetControlRotation()).GetScaledAxis(EAxis::X);
        MyCharacter->AddMovementInput(Direction, Value.Get<float>());
    }
}

void ACE901_PlayerController::MoveRight(const FInputActionValue& Value)
{
    ACharacter* MyCharacter = Cast<ACharacter>(GetPawn());
    if (MyCharacter)
    {
        FVector Direction = FRotationMatrix(MyCharacter->GetControlRotation()).GetScaledAxis(EAxis::Y);
        MyCharacter->AddMovementInput(Direction, Value.Get<float>());

        // Rotate the character to face the movement direction
        if (Value.Get<float>() != 0.0f)
        {
            FRotator NewRotation = FRotator(0.0f, MyCharacter->GetControlRotation().Yaw + (Value.Get<float>() < 0 ? -90.0f : 90.0f), 0.0f);
            MyCharacter->SetActorRotation(NewRotation);
        }
    }
}
