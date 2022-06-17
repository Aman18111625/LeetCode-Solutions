class H2O {
  std::mutex m;
  std::condition_variable cv;
  int turn;
public:
    H2O() {
        turn=0;
    }

    void hydrogen(function<void()> releaseHydrogen) {
        
        // releaseHydrogen() outputs "H". Do not change or remove this line.
        std::unique_lock<std::mutex>lock(m);
        while(turn==2){
          cv.wait(lock);
        }
        releaseHydrogen();
        turn++;
        cv.notify_all();
    }

    void oxygen(function<void()> releaseOxygen) {
        
        // releaseOxygen() outputs "O". Do not change or remove this line.
        std::unique_lock<std::mutex>lock(m);
        while(turn<2){
          cv.wait(lock);
        }
        releaseOxygen();
        turn=0;
        cv.notify_all();
    }
};