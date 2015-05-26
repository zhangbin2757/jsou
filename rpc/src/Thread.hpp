/*
 * Thread.hpp
 *
 *  Created on: May 26, 2015
 *      Author: zhangbin
 */

#ifndef THREAD_HPP_
#define THREAD_HPP_

#include <pthread.h>

namespace jsou {
class Runnable {
public:
	virtual void Run() = 0;
	virtual ~Runnable() {
	}
};

class Cond {
public:
	Cond() {
		pthread_mutex_init(&mMutex, NULL);
		pthread_cond_init(&mCond, NULL);
	}
	virtual ~Cond() {
		pthread_cond_destroy(&mCond);
		pthread_mutex_destroy(&mMutex);
	}
	int32_t Lock() {
		return pthread_mutex_lock(&mMutex);
	}
	int32_t UnLock() {
		return pthread_mutex_unlock(&mMutex);
	}
	int32_t Wait() {
		return pthread_cond_wait(&mCond, &mMutex);
	}
	int32_t Notify() {
		return pthread_cond_signal(&mCond);
	}
	int32_t Broadcast() {
		return pthread_cond_broadcast(&mCond);
	}
private:
	pthread_mutex_t mMutex;
	pthread_cond_t mCond;
};

class Thread {
private:
	static void* func(void *token) {
		Thread *thread = static_cast<Thread*>(token);
		thread->mRunning = true;
		thread->mCond->Notify();
		if (thread->mRunnable) {
			thread->mRunnable->Run();
		}
		thread->mRunning = false;
		return 0;
	}
public:
	Thread(Runnable *runnable) :
			mTid(0), mRunning(false), mRunnable(runnable) {
		mCond = new Cond;
	}
	virtual ~Thread() {
		delete mCond;
	}
	inline bool IsRunning() {
		return mRunnable;
	}
	inline uint64_t GetId() {
		return mTid;
	}
	inline Thread* Start() {
		if (!mRunning) {
			pthread_attr_t attr;
			pthread_attr_init(&attr);
			pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);
			pthread_create(&mTid, &attr, func, this);
			pthread_attr_destroy(&attr);
			mCond->Wait();
			mRunning = true;
		}
		return this;
	}
	inline Thread* Join() {
		if (mRunning && pthread_self() != mTid) {
			pthread_join(mTid, NULL);
		}
		return this;
	}
private:
	pthread_t mTid;
	bool mRunning;
	Cond *mCond;
	Runnable *mRunnable;
};

}

#endif /* THREAD_HPP_ */
