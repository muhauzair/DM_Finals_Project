#include<iostream>
#include<cmath>
using namespace std;
bool exists(int arr[], int size, int val){
    for(int i = 0; i < size; i++){
        if(arr[i] == val) 
        return true;
    }
    return false;
}
int main(){
    int totalSets;
    cout<<"********************************************************************************************************"<<endl;
    
    cout << "@@@@@@  @@@@@@  @@@@@@     @@@@@@  @@@@@@  @@@@@@  @@@@@@  @@@@@@  @@@@@@  @@@@@@  @@@@@@  @@@@    @@" <<endl;
    cout << "@@      @@        @@       @@  @@  @@  @@  @@      @@  @@  @@  @@    @@      @@    @@  @@  @@ @@   @@" <<endl;
    cout << "@@@@@@  @@@@      @@       @@  @@  @@@@@@  @@@@    @@@@@@  @@@@@@    @@      @@    @@  @@  @@  @@  @@" <<endl;
    cout << "    @@  @@        @@       @@  @@  @@      @@      @@@@    @@  @@    @@      @@    @@  @@  @@   @@ @@" <<endl;
    cout << "@@@@@@  @@@@@@    @@       @@@@@@  @@      @@@@@@  @@  @@  @@  @@    @@    @@@@@@  @@@@@@  @@    @@@@" <<endl;
    cout << "\n                                   --- VISUALIZER ---                                              " <<endl;
    cout<<"********************************************************************************************************"<<endl;
    cout<<"This program only deal with at most 3 sets.";
    cout<<"Enter number of sets: ";
    cin>>totalSets;
    int setSizes[50];
    int sets[50][100];
    for(int i = 0; i < totalSets; i++){
        cout<<"Enter number of elements in Set "<<i + 1<<": ";
        cin>>setSizes[i];
        cout<<"Enter elements for Set "<<i + 1<<": ";
        for(int j = 0; j < setSizes[i]; j++)
            cin>>sets[i][j];
    }
    int choice;
    do{
        cout<<"--- CHOOSE OPERATION ---"<<endl;
        cout<<"1. Union\n";
        cout<<"2. Intersection\n";
        cout<<"3. Difference\n";
        cout<<"4. Power Set\n";
        cout<<"5. Text-Based Venn Diagram (All Sets)\n";
        cout<<"0. Exit\n";
        cout<<"Choice: ";
        cin>>choice;
        int s1, s2;
        switch (choice){
            case 1:{
                cout << "\n--- [ UNION OPERATION ] ---" << endl;
                cout << "Definition: The Union of two setscontains all elements from both sets,\nwithout duplicating shared elements." << endl;
                if(totalSets==1){
                    cout<<"Union is not possible. Please enter at least 2 sets. "<<endl;
                    break;
                }
                else if(totalSets==2||totalSets==3){  
                cout<<"Enter two set numbers for UNION (e.g. 1 3): ";
                cin>>s1>>s2;
                s1--; s2--;

                cout<<"Union = { ";
                for(int i = 0; i < setSizes[s1]; i++)
                    cout<<sets[s1][i]<<" ";

                for(int i = 0; i < setSizes[s2]; i++)
                    if(!exists(sets[s1], setSizes[s1], sets[s2][i]))
                        cout<<sets[s2][i]<<" ";

                cout<<"}\n";
                break;
                }
                else{
                    cout<<"Our project is not handling it."<<endl;
                    cout<<"Please enter at most 3 sets."<<endl;
                    break;
                }
            }
            case 2:{
                cout<<"              ---[Intersection]---           "<<endl;
                cout<<"The Intersection of two sets set A and set B \n is a set that contains only the elements that are \n common to both sets. If an element is in $A$ but \n not in $B$, it will not be included."<<endl;
                if(totalSets==1){
                    cout<<"Intersection is not possible. Please enter at least 2 sets. "<<endl;
                    break;
                }
                else if(totalSets==2||totalSets==3){   
                cout<<"Enter two set numbers for INTERSECTION (e.g. 1 2): ";
                cin>>s1>>s2;
                s1--; s2--;
                cout<<"Intersection = { ";
                for(int i = 0; i < setSizes[s1]; i++)
                    if(exists(sets[s2], setSizes[s2], sets[s1][i]))
                        cout<<sets[s1][i]<<" ";

                cout<<"}"<<endl;
                break;
                }
                else{
                    cout<<"Our project is not handling it."<<endl;
                    cout<<"Please enter at most 3 sets."<<endl;
                    break;
                }
            }
            case 3:{
                cout<<"                  ---[Difference]---               "<<endl;
                cout<<"The Difference of two sets A and B (written as A - B)\n is the set of elements that belong to $A$ but do not belong \n to B. Think of it as Set A minus everything it shares with B."<<endl;
                if(totalSets==1){
                    cout<<"Differnce isn't possible. Please enter at least 2 sets. "<<endl;
                    break;
                }
                else if(totalSets==2||totalSets==3){ 
                cout<<"Enter two set numbers for DIFFERENCE A - B (e.g. 2 1): ";
                cin>>s1>>s2;
                s1--; s2--;
                cout<<"Difference = { ";
                for(int i = 0; i < setSizes[s1]; i++)
                    if(!exists(sets[s2], setSizes[s2], sets[s1][i]))
                        cout<<sets[s1][i]<<" ";
                cout<<"}"<<endl;
                break;
                }
                else{
                    cout<<"Our project is not handling it."<<endl;
                    cout<<"Please enter at most 3 sets."<<endl;
                    break;
                }
            }
            case 4:{
                cout<<"                  ---[Power Set]---               "<<endl;
                cout<<"A Power Set is a set that contains all possible subsets of a given set A, including the Empty Set and the set itself"<<endl;
                 if(totalSets==1||totalSets==2||totalSets==3){
                cout<<"Enter set number for POWER SET (e.g. 3): ";
                cin>>s1;
                s1--;
                int psize = pow(2, setSizes[s1]);
                cout<<"Power Set has "<<psize<<" subsets:"<<endl;
                for(int i = 0; i < psize; i++){
                    cout<<"{ ";
                    for(int j = 0; j < setSizes[s1]; j++)
                        if(i & (1 << j))
                            cout<<sets[s1][j]<<" ";
                    cout<<"}"<<endl;
                }
                break;
                }
                else{
                    cout<<"Our project is not handling it."<<endl;
                    cout<<"Please enter at most 3 sets."<<endl;
                    break;
                }
            }
            case 5:{
                cout<<"              ---[Venn diagram]---           "<<endl;
                cout << "          _ _ _ _          " << endl;
                cout<<"          SET A               SET B"<<endl;
                cout<<"              _ _ _ _               _ _ _ _"<<endl;
                cout<<"            /        \\            /        \\"<<endl;
                cout<<"           /          \\  _ _ _  /           \\"<<endl;
                cout<<"          |             /      \\             |"<<endl;
                cout<<"          |            | Overlap|             |"<<endl;
                cout<<"          \\            \\ _ _ _  /           /"<<endl;
                cout<<"           \\ _ _ _ _ /          \\ _ _ _ _ /"<<endl;

                cout<<"A Venn Diagram is a visual way to represent sets and their relationships. It usually uses circles to show sets."<<endl;
                cout<<"1. Overlapping circles show that sets share elements (Intersection).";
                cout<<"2. Separated circles show Disjoint sets (no common elements)."<<endl;
                cout<<"3. A circle inside another circle shows a Subset."<<endl;  
                if(totalSets == 1){
                    cout << "Only in A: { ";
                    for(int i = 0; i < setSizes[s1]; i++)
                        cout<<sets[s1][i]<<" ";
                    cout<<"}"<<endl;    
                }
                else if(totalSets == 2){
                    int A = 0, B = 1;
                    cout << "Common in A and B: { ";
                    for(int i = 0; i < setSizes[A]; i++){
                        int x = sets[A][i];
                        if(exists(sets[B], setSizes[B], x))
                            cout << x << " ";
                    }
                    cout << "}\n";
                    cout << "Only in A: { ";
                    for(int i = 0; i < setSizes[A]; i++){
                        int x = sets[A][i];
                        if(!exists(sets[B], setSizes[B], x))
                            cout << x << " ";
                    }
                    cout << "}\n";
                    cout << "Only in B: { ";
                    for(int i = 0; i < setSizes[B]; i++){
                        int x = sets[B][i];
                        if(!exists(sets[A], setSizes[A], x))
                            cout << x << " ";
                    }
                    cout << "}\n";
                    cout << "----------------------------------\n";
                }
                else if(totalSets == 3){
                    int A = 0, B = 1, C = 2;
                    cout << "Common in ALL (A ∩ B ∩ C): { ";
                    for(int i = 0; i < setSizes[A]; i++){
                        int x = sets[A][i];
                        if(exists(sets[B], setSizes[B], x) && exists(sets[C], setSizes[C], x))
                            cout << x << " ";
                    }
                    cout << "}\n";
                    cout << "Common in A and B only: { ";
                    for(int i = 0; i < setSizes[A]; i++){
                        int x = sets[A][i];
                        if(exists(sets[B], setSizes[B], x) && !exists(sets[C], setSizes[C], x))
                            cout << x << " ";
                    }
                    cout << "}\n";
                    cout << "Common in A and C only: { ";
                    for(int i = 0; i < setSizes[A]; i++){
                        int x = sets[A][i];
                        if(exists(sets[C], setSizes[C], x) && !exists(sets[B], setSizes[B], x))
                            cout << x << " ";
                    }
                    cout << "}\n";
                    cout << "Common in B and C only: { ";
                    for(int i = 0; i < setSizes[B]; i++){
                        int x = sets[B][i];
                        if(exists(sets[C], setSizes[C], x) && !exists(sets[A], setSizes[A], x))
                            cout << x << " ";
                    }
                    cout << "}\n";
                    cout << "Only in A: { ";
                    for(int i = 0; i < setSizes[A]; i++){
                        int x = sets[A][i];
                        if(!exists(sets[B], setSizes[B], x) && !exists(sets[C], setSizes[C], x))
                            cout << x << " ";
                    }
                    cout << "}\n";
                    cout << "Only in B: { ";
                    for(int i = 0; i < setSizes[B]; i++){
                        int x = sets[B][i];
                        if(!exists(sets[A], setSizes[A], x) && !exists(sets[C], setSizes[C], x))
                            cout << x << " ";
                    }
                    cout << "}\n";
                    cout << "Only in C: { ";
                    for(int i = 0; i < setSizes[C]; i++){
                        int x = sets[C][i];
                        if(!exists(sets[A], setSizes[A], x) && !exists(sets[B], setSizes[B], x))
                            cout << x << " ";
                    }
                    cout << "}\n";
                    cout << "----------------------------------\n";
                }
                else {
                    cout<<"Our project is not handling it."<<endl;
                    cout<<"Please enter at most 3 sets."<<endl;
                    break;
                }
                break;
            }
        } 
    } while(choice != 0);
    return 0;
}
