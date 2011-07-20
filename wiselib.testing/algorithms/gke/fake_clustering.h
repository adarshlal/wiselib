#ifndef _FAKECLUSTERING_H
#define _FAKECLUSTERING_H

#include "util/delegates/delegate.hpp"

namespace wiselib {
    template<typename OsModel_P,
    typename Radio_P,
    typename Timer_P,
    typename Debug_P>

    class FakeClustering {
    public:
        typedef OsModel_P OsModel;
        typedef Radio_P Radio;
        typedef Timer_P Timer;
        typedef Debug_P Debug;
        typedef FakeClustering<OsModel_P, Radio_P, Timer_P, Debug_P> self_t;

        typedef int cluster_id_t;
        typedef int cluster_level_t;
        typedef typename Radio::node_id_t node_id_t;
        typedef typename Radio::size_t size_t;
        typedef typename Radio::block_data_t block_data_t;
        typedef wiselib::vector_static<OsModel, node_id_t, 200 > vector_t;

        typedef delegate1<void, int> cluster_delegate_t;

        cluster_level_t cluster_level() {
            return 0;
        }

        cluster_id_t cluster_id() {
            return 0;
        }

        bool cluster_head() {
            if(radio_->id() == 5344 || radio_->id() == 3)	// 0x14e0 Wiselib, 3 Shawn
            //if(radio_->id() == 0)
            	return 1;			// don't laugh !
            return 0;
        }

        node_id_t parent() {
            return 0;
        }

        size_t hops() {
            return 1;
        }

        template<class T, void (T::*TMethod)(int) >
        inline int reg_changed_callback(T *obj_pnt) {
            state_changed_callback_ = cluster_delegate_t::from_method<T, TMethod > (obj_pnt);
            return state_changed_callback_;
        }

        void unreg_changed_callback(int idx) {
            state_changed_callback_ = cluster_delegate_t();
        }

        void init(Radio& radio, Timer& timer, Debug& debug) {
             radio_ = &radio;
             timer_ = &timer;
             debug_ = &debug;
        }

        void enable(void) { }

        void disable(){ }

    private:

        Radio *radio_;
        Timer *timer_;
        Debug *debug_;

        cluster_delegate_t state_changed_callback_;
    };
}

#endif
