#include <stdio.h>
#include <string.h>
enum {
    INSERT,
    SEARCH,
    DELETE,
    UPDATE
};
typedef struct tel{
    char name[30];
    char tel[30];
}Tel;
Tel arr[20] ={
    {"홍길동", "01012345678"},
};
int idx = 1;
void InsertTel(){
    if(idx == 20){
        printf("더이상 저장할 공간이 없습니다\n");
        return;
    }
    printf("이름 입력 : ");
    scanf(" %s",arr[idx].name);
    printf("핸드폰번호 입력 : ");
    scanf(" %d",&arr[idx].tel);
    idx++;//인덱스 번호 하나 증가
}