#include "mpl.hpp"

namespace zutils {
	namespace mpl {
		namespace test {
			template<typename T>
			struct type_wrapper {};

			template<class T1, class T2>
			inline void assert_same_type(T1, T2) {
				type_wrapper<T1>{} = type_wrapper<T2>{};
			}

			void mpl_change();
			void mpl_push_back();
			void mpl_size();
			void mpl_push_front();
			void mpl_transform();
			void mpl_contains();
			void mpl_at_c();
			void mpl_count();
			void mpl_erase_all();
			void mpl_reverse();
		}
	}
}