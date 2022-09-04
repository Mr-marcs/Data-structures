#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

int main(){
    int data[] = {22,23,24,24,24,24,24,24,24,25,27,27,27,27,27,27,25,32,33,34,34,34,34,34,34,34,35,37,37,37,37,37,37,35,34,35};
    int length = sizeof(data)/sizeof(data[0]);
    node_t* marco = create_node(data[0]);
    
    printf("Data -> ");
    for(int i=1;i<length;i++){
        printf("%d ",data[i]);
        tree_push(marco,data[i]);
    }

    printf("\n");

    length = count_nodes(marco)*2;
    int arr[length],value,frequency;
    convert_to_array(marco,0,arr);
    
    printf("Compreesed data -> ");
    for(int i=0;i<length;i+=2){
       value = arr[i];
       frequency = arr[i+1];

       if(frequency > 1){
            printf("AA %d %d ",value,frequency);
       }
       else{
            printf("%d ",value);
       }
    }
    free_tree(marco);
    return 0;
}