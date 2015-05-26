/*
 * Mutex.hpp
 *
 *  Created on: May 21, 2015
 *      Author: zhangbin
 */

#ifndef MUTEX_HPP_
#define MUTEX_HPP_

#include <pthread.h>

namespace jsou {
class Mutex {
public:
	Mutex(bool recursive = true) {
		if (recursive) {
			pthread_mutexattr_t attr;
			if (pthread_mutexattr_init(&attr) == 0) {
				pthread_mutexattr_settype(&attr, PTHREAD_MUTEX_RECURSIVE);
				pthread_mutex_init(&mMutex, &attr);
				pthread_mutexattr_destroy(&attr);
			}
		} else {
			pthread_mutex_init(&mMutex, NULL);
		}
	}

	~Mutex() {
		pthread_mutex_destroy(&mMutex);
	}

	void Lock() {
		pthread_mutex_lock(&mMutex);
	}

	void UnLock() {
		pthread_mutex_unlock(&mMutex);
	}
private:
	pthread_mutex_t mMutex;
};
}

#endif /* MUTEX_HPP_ */
