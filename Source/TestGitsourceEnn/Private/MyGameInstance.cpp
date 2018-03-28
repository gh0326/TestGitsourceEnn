// Fill out your copyright notice in the Description page of Project Settings.

#include "MyGameInstance.h"
#include "Engine/Engine.h"

#include "UObject/ConstructorHelpers.h"
#include "Blueprint/UserWidget.h"

#include "UmgSystem/MainWidget.h"

UMyGameInstance::UMyGameInstance(const FObjectInitializer & ObjectInitializer)
{
	
	ConstructorHelpers::FClassFinder<UUserWidget> MainMenu(TEXT("/Game/UMG/MainMenu"));
	if (!ensure(MainMenu.Class != nullptr))return;

	mainmenuclass = MainMenu.Class;
	UE_LOG(LogTemp, Warning, TEXT("GameInstance -----Constructor-----"));

	
}



void UMyGameInstance::Init()
{
	UE_LOG(LogTemp, Warning, TEXT("GameInstance -----Init-----"));


}

void UMyGameInstance::host()
{
	UEngine* mEngine = GetEngine();
	if (!ensure(mEngine != nullptr))return;
	
	mEngine->AddOnScreenDebugMessage(0, 5.f, FColor::Yellow,TEXT("---HOST---"));

	UWorld* World = GetWorld();
	if (!ensure(World != nullptr))return;

	World->ServerTravel("/Game/Map/Level01?listen");
	
	
}

void UMyGameInstance::loadmainmenu()
{

	UMainWidget* Menu = CreateWidget<UMainWidget>(this, mainmenuclass);
	if (!ensure(Menu != nullptr))return;
    Menu->AddToViewport();
	Menu->SetInterface(this);

	APlayerController* pc = GetFirstLocalPlayerController();
	if (!ensure(pc != nullptr))return;
	pc->bShowMouseCursor=true;

}

void UMyGameInstance::join(const FString& url)
{
	APlayerController* pc = GetFirstLocalPlayerController();
	if (!ensure(pc != nullptr))return;

	pc->ClientTravel(url, ETravelType::TRAVEL_Absolute);
}
