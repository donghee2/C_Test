#include <stdio.h>
#include <string.h>
enum {
    EXIT,
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
    idx++;
    printf("등록완료.\n");
}
void SearchTel(){
    char str[30];
    printf("검색할 이름 입력 : ");
    scanf("%s",str);
    for(int i=0;i<idx;i++){
        if(strcmp(arr[i].name,str) == 0){
            printf("%s %d %c\n",arr[i].name, arr[i].tel);  
            return;
        }
    }
    printf("검색 결과가 없습니다.\n");
}
void DeleteTel(){
    char str[30];
    printf("삭제할 이름 입력 : ");
    scanf("%s",str);
    for(int i=0;i<idx;i++){
        if(strcmp(arr[i].name,str) == 0){
            for(int j=i;j<idx-1;j++)
                arr[j] = arr[j+1];
            idx--;
            return;
        }
    }
    printf("삭제할 데이터가 없습니다.\n");
}
void UpdateTel(){
    char search[30];
    int flag = 0;
    printf("검색할 이름을 입력하세요 : ");
    scanf(" %s", search );
    for(int i=0; i<idx;i++){
        if(strcmp(search, arr[i].name) == 0){
            printf("수정할 연락처를 입력하세요 : ");
            scanf(" %s", arr[i].tel);
            flag = 1;
        }
    }
    if(flag == 1) printf("연락처 수정 완료\n");
    else printf("검색한 사용자를 찾을 수 없습니다\n");

}
int main(void){
    int no = -1;

    while(no != EXIT){
        puts("--- 연락처 관리 프로그램---");
        puts("1. 등록");
        puts("2. 검색");
        puts("3. 삭제");
        puts("4. 수정");
        puts("0. 프로그램 종료");
        puts("원하시는 메뉴 번호 입력 : ");
        scanf("%d",&no);

        switch(no){
            case INSERT:
                InsertTel();
                break;
            case SEARCH:
                SearchTel();
                break;
            case DELETE:
                DeleteTel();
                break;
            case UPDATE:
                UpdateTel();
                break;
        }
    }

    return 0;
}






