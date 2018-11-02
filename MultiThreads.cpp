//
// Created by lenovo on 2018/10/31.
//

#include <stdio.h>
#include <stdlib.h>

#include <chrono>    // std::chrono::seconds
#include <iostream>  // std::cout
#include <thread>    // std::thread, std::this_thread::sleep_for

void thread_task1(std::string str) {
    //std::this_thread::sleep_for(std::chrono::seconds(n));
    std::cout <<str<<std::endl;
        //<< std::this_thread::get_id()
        //<< " paused " << n << " seconds" << std::endl;
}

void thread_task2(std::string str) {
    //std::this_thread::sleep_for(std::chrono::seconds(n));
    std::cout <<str<<std::endl;
              //<< std::this_thread::get_id()<<std::endl;
              //<< " paused " << n << " seconds" << std::endl;
}

/*
 * ===  FUNCTION  =========================================================
 *         Name:  main
 *  Description:  program entry routine.
 * ========================================================================
 */
int main(int argc, const char *argv[])
{
    std::thread threads[50];
    std::cout << "Spawning 5 threads...\n";
    for (int i = 0; i < 50; i++) {
        if(i<25)
            threads[i] = std::thread(thread_task1, "hello1 ...");
        else
            threads[i] = std::thread(thread_task2, "hello2 ...");
    }
    std::cout << "Done spawning threads! Now wait for them to join\n";
    for (auto& t: threads) {
        t.join();
    }
    std::cout << "All threads joined.\n";

    return EXIT_SUCCESS;
}  /* ----------  end of function main  ---------- */