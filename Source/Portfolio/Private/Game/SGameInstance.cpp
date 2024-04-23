// Fill out your copyright notice in the Description page of Project Settings.


#include "Game/SGameInstance.h"
#include "Kismet/KismetSystemLibrary.h"


USGameInstance::USGameInstance()
{
	UE_LOG(LogTemp, Log, TEXT("경고나 에러가 아닙니다."));

	Name = TEXT("USGameInstance에서 Name변수값을 설정했습니다");
}

void USGameInstance::Init()
{
	Super::Init(); // 엔진 업데이트 루틴을 지키기 위해서, 언리얼 엔지니어가 작성한 코드가 먼저 실행되게끔 하기 위함.
	
	UE_LOG(LogTemp, Log, TEXT("게임이 시작되었습니다."));

	UKismetSystemLibrary::PrintString(this, TEXT("프린트 스트링 : 게임이 실행될 때 출력"));

	UClass* RuntimeClassInfo = GetClass();
	UClass* CompleteClassInfo = StaticClass();

	UE_LOG(LogTemp, Log, TEXT("Class Name : %s"),*RuntimeClassInfo->GetName());




}

void USGameInstance::Shutdown()
{
	Super::Shutdown(); // 엔진 업데이트 루틴을 지키기 위해서, 언리얼 엔지니어가 작성한 코드가 먼저 실행되게끔 하기 위함.

	UE_LOG(LogTemp, Log, TEXT("게임이 꺼졌습니다."));

	
}
