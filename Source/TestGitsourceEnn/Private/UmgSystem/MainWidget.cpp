// Fill out your copyright notice in the Description page of Project Settings.

#include "MainWidget.h"
#include "MyUMGInterface.h"
#include "Button.h"



bool UMainWidget::Initialize()
{
	if (Super::Initialize())
	{
		host->OnClicked.AddDynamic(this, &UMainWidget::dohost);

		

		return true;
	}

	return false;

}

void UMainWidget::SetInterface(IMyUMGInterface * inter)
{
	Interface = inter;
}

void UMainWidget::dohost()
{

	if (Interface != nullptr) {
	Interface->host();

	UE_LOG(LogTemp, Warning, TEXT("===host==="));
	}

}
