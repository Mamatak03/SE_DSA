/*Q.B5] A book consists of chapters, chapters consist of sections and sections consist of
subsections. Construct a tree and print the nodes. Find the time and space requirements
of your method.*/

#include <iostream>
#include <string>
using namespace std;

struct node
{
    string label;        
    int ch_count;        
    struct node *child[10];  
};

class GT
{
public:
    node* root;

    GT()
    {
        root = NULL;
    }

    
    void create()
    {
        root = new node;

        cout << "Name of the book:\t";
        cin >> root->label;
        cout << "Number of chapters:\t";
        cin >> root->ch_count;

        
        for (int i = 0; i < root->ch_count; i++)
        {
            root->child[i] = new node;
            cout << "Name of chapter " << i + 1 << ":\t";
            cin >> root->child[i]->label;
            cout << "Number of sections:\t";
            cin >> root->child[i]->ch_count;

           
            for (int j = 0; j < root->child[i]->ch_count; j++)
            {
                root->child[i]->child[j] = new node;
                cout << "Name of section " << i + 1 << " - " << j + 1 << ":\t";
                cin >> root->child[i]->child[j]->label;
                cout << "Number of sub-sections:\t";
                cin >> root->child[i]->child[j]->ch_count;

                for (int k = 0; k < root->child[i]->child[j]->ch_count; k++)
                {
                    root->child[i]->child[j]->child[k] = new node;
                    cout << "Name of sub-section " << i + 1 << " - " << j + 1 << " - " << k + 1 << ":\t";
                    cin >> root->child[i]->child[j]->child[k]->label;
                }
            }
        }
    }

    
    void display(node *r)
    {
        cout << endl << "Name of book:\t" << r->label << endl;
        cout << "Number of chapters:\t" << r->ch_count << endl;

        for (int i = 0; i < r->ch_count; i++)
        {
            cout << endl << "Name of chapter " << i + 1 << ":\t" << r->child[i]->label << endl;
            cout << "Number of sections:\t" << r->child[i]->ch_count << endl;

            for (int j = 0; j < r->child[i]->ch_count; j++)
            {
                cout << "\tSection " << i + 1 << " - " << j + 1 << ":\t" << r->child[i]->child[j]->label << endl;
                cout << "\tNumber of sub-sections:\t" << r->child[i]->child[j]->ch_count << endl;

                for (int k = 0; k < r->child[i]->child[j]->ch_count; k++)
                {
                 cout << "\t\tSub-section " << i + 1 << " - " << j + 1 << " - " << k + 1 << ":\t" << r->child[i]->child[j]->child[k]->label << endl;
                }
            }
        }
    }

    
    void cleanup(node* r)
    {
        for (int i = 0; i < r->ch_count; i++)
        {
            for (int j = 0; j < r->child[i]->ch_count; j++)
            {
                for (int k = 0; k < r->child[i]->child[j]->ch_count; k++)
                {
                    delete r->child[i]->child[j]->child[k];
                }
                delete r->child[i]->child[j];
            }
            delete r->child[i];
        }
        delete r;
    }
};

int main()
{
    GT g;

    while (1)
    {
        cout << "--- MAIN MENU ---" << endl;
        cout << "1 - Add book info" << endl;
        cout << "2 - Display info" << endl;
        cout << "3 - Exit" << endl;
        cout << "Choose an option (1-3):\t";
        int ch;
        cin >> ch;

        switch (ch)
        {
        case 1:
            g.create();
            break;
        case 2:
            g.display(g.root);
            break;
        case 3:
            cout << endl << "// END OF CODE\n\n";
            g.cleanup(g.root); 
            exit(0);
            break;
        default:
            cout << "Please choose a valid option (1-3).\n";
            break;
        }
    }
}

