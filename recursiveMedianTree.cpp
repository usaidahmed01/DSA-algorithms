#include<iostream>
#include<vector>
using namespace std;

struct tree{
    int data;
    tree *s1;
    tree *s2;
    tree *s3;
    tree *s4;
};

void preOrder(tree* node){
    if(node == NULL) return;

    // Process current node
    cout << node->data << " ";

    // Recursively process the 4 subtrees
    preOrder(node->s1);
    preOrder(node->s2);
    preOrder(node->s3);
    preOrder(node->s4);
}


int Median(vector<int> &array){
    /*sizeof gives size in bytes, we take that and divide it with byte of 1 element too get
    the nmber of elements*/
    int size = array.size();
    int M = array[size/2];
    return M;
}

tree* treeMaking(vector<int> array){
    if(array.size()==0) return NULL;
    
    
    tree *temp = new tree();
    temp->s1=NULL;
    temp->s2=NULL;
    temp->s3=NULL;
    temp->s4=NULL;
    int median = Median(array);   
    temp->data = median;  

    int size = (array.size()+3)/4;


    vector<int>sub1;
    vector<int>sub2;
    vector<int>sub3;
    vector<int>sub4;
        
    for(int i=0; i<array.size(); i++){

        if(array[i] == median){
            continue;
        }
        else if(array[i] < (median/2) && sub1.size() < size){
            sub1.push_back(array[i]);
        }
        else if(array[i] >= (median/2) && array[i] < median && sub2.size() < size){
            sub2.push_back(array[i]);
        }
        else if(array[i] >= median && array[i] < (3*median/2) && sub3.size() < size){
            sub3.push_back(array[i]);
        }
        else{
            sub4.push_back(array[i]);
        }
        
    }

    temp->s1 = treeMaking(sub1);
    temp->s2 = treeMaking(sub2);
    temp->s3 = treeMaking(sub3);
    temp->s4 = treeMaking(sub4);

    return temp;
}

int main(){
    tree *root = NULL;
    vector<int> array;
    array.push_back(22);
    array.push_back(44);
    array.push_back(75);
    array.push_back(90);
    array.push_back(92);
    array.push_back(99);
    array.push_back(110);
    array.push_back(112);
    array.push_back(125);
    array.push_back(130);
    array.push_back(131);
    cout<<"Dheeraj rakhiye janab ban rha h\n\n";
    
    // int size=sizeof(array)/sizeof(array[0]);
    root = treeMaking(array);
    cout<<"Bana lya darakht?? ab shaat ho! \n\nKya mtlb dekhna bh h??\n\nAcha chalo 1 dabao jldi!";;
    int input;
    cin>>input;
    if(input==1)
    preOrder(root);
}
