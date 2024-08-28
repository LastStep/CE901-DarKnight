// Copyright Epic Games, Inc. All Rights Reserved.

#include "CE901_GameGameMode.h"
#include "CE901_GamePlayerController.h"
#include "CE901_GameCharacter.h"
#include "CE901_PlayerController.h"
#include "UObject/ConstructorHelpers.h"

ACE901_GameGameMode::ACE901_GameGameMode()
{
	// use our custom PlayerController class
	PlayerControllerClass = ACE901_GamePlayerController::StaticClass();

	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/TopDown/Blueprints/BP_TopDownCharacter"));
	if (PlayerPawnBPClass.Class != nullptr)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}

	// set default controller to our Blueprinted controller
	static ConstructorHelpers::FClassFinder<APlayerController> PlayerControllerBPClass(TEXT("/Game/TopDown/Blueprints/BP_TopDownPlayerController"));
	if(PlayerControllerBPClass.Class != NULL)
	{
		PlayerControllerClass = PlayerControllerBPClass.Class;
	}
}