#pragma once

#include <iostream>
#include <vector>

template <typename T>
class sorting
{
private:
    // O(n)
    std::vector<T> merge(std::vector<T>& splitted_a, std::vector<T>& splitted_b) {
        std::vector<T> c_merged;

        uint64_t i = 0, j = 0;
        while (i < splitted_a.size() && j < splitted_b.size()) {
            if (splitted_a[i] > splitted_b[j]) {
                c_merged.push_back(splitted_b[j]);
                j++;
            }
            else {
                c_merged.push_back(splitted_a[i]);
                i++;
            }
        }

        while (i < splitted_a.size()) {
            c_merged.push_back(splitted_a[i]);
            i++;
        }

        while (j < splitted_b.size()) {
            c_merged.push_back(splitted_b[j]);
            j++;
        }

        return c_merged;
    }

public:
    // O(n^2)
    void insertion_sort(std::vector<T> &target) {
        for (const auto& it : target) {
            const auto index = &it - &target[0];
            auto temp = it;

            for (auto i = 0; i <= index; i++)
            {
                auto key = index - i;

                if (index != 0 && key != 0 && target[key - 1] > temp)
                {
                    target[key] = target[key - 1];
                    target[key - 1] = temp;
                }

            }

        }
    }

    //O(n^2)
    void bubble_sort(std::vector<T> &target)
    {
		for(uint64_t i = 0; i < target.size(); i++)
		{
            for(uint64_t j = 0; j < target.size(); j++)
            {
	            if(target[i] < target[j])
	            {
                    std::swap(target[i], target[j]);
	            }
            }
		}
    }

    // O(n^2)
    void selection_sort(std::vector<T>& target)
    {
        const uint64_t n = target.size();

        for (uint64_t i = 0; i < n; i++)
        {
            uint64_t min_index = i;

            for(uint64_t j = i + 1; j < n; j++)
	            if(target[j] < target[min_index])
                    min_index = j;

            if(min_index != i)
				std::swap(target[min_index], target[i]);
        }
    }



    // O(n logn)
    void merge_sort(std::vector<T> &target) {
        if (target.size() == 1)
            return;

        std::vector<T> l;
        std::vector<T> r;
        auto mid = target.size() / 2;

        for (uint64_t i = 0; i < mid; i++)
        {
            l.reserve(mid - 1);
            l.push_back(target[i]);
        }

        for (auto i = mid; i < target.size(); ++i)
        {
            l.reserve(target.size() - mid);
            r.push_back(target[i]);
        }

        merge_sort(l);
        merge_sort(r);

        target = merge(l, r);
    }

    // Print O(n)
    void print_array(const std::vector<T> &target)
    {
        for (const auto& value : target) {
            const auto index = &value - &target[0];
            std::cout << "[" << index << "," << value << "] ";
        }
    }

    // Get singleton
    static sorting& get()
    {
        static sorting instance;
        return instance;
    }
};
