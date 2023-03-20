#include<iostream>
#include<vector>
#include<bitset>
#define SIZE 80

using namespace std;

struct Bitset
{
    private:

        vector< bitset<SIZE> > Subsets;

        int full_set_size;

    public:

        Bitset(const int &full_set_size,const int &subset_count)
        {
            this->full_set_size = full_set_size;
            Subsets.resize(subset_count);

            for(auto &i : Subsets)
            {
                int tmp_1;
                cin >> tmp_1;
                while(--tmp_1 >= 0)
                {
                    int tmp_2;
                    cin >> tmp_2;
                    i.set(--tmp_2);
                }
            }
        }

        int minSetCover(const bitset<SIZE> curr_combined_set, const int curr_set)
        {
            if((int)curr_combined_set.count() == full_set_size)
            {
                return 0;
            }

            if(curr_set == (int)Subsets.size())
            {
                return -1;
            }

            int best_without = minSetCover(curr_combined_set, curr_set + 1),
            best_with = minSetCover(curr_combined_set | Subsets[curr_set], curr_set + 1);

            if(best_with < best_without)
            {
                if(best_with != -1)
                {
                    return best_with + 1; 
                }
                else
                {
                    return best_without;
                }
            }

            if(best_without < best_with)
            {
                if(best_without != -1)
                {
                    return best_without; 
                }
                else
                {
                    return best_with + 1;
                }
            }

            return best_without;
        }
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int light_count, switch_count;
    cin >> light_count >> switch_count;

    Bitset S(light_count, switch_count);

    cout << S.minSetCover(bitset<SIZE>(), 0);

    return 0;
}