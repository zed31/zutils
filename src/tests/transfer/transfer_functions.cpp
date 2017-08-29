#include "transfer_test.hpp"

namespace zutils {
	namespace transfer {
		
		/* Creating type transfer */
		template<typename T>
		struct add_pointer {
			using type = T*;
		};
		using add_pointer_t = meta_container<add_pointer>;

		/* Create bridge between mpl:: and "runtime" */
		using add_pointer_meta_t = meta_container<mpl::add_pointer_meta>;

		/* Test for type_wrapper<T> meta_container<f> and metafunction */
		void test::meta_function() {
			int *i{};
			assert_same_type(add_pointer_t::apply<int>::type{}, decltype(m_type<int *>)::type{});
			assert_same_type(add_pointer_t::apply<int>::type{}, i);
			auto meta_f_result = apply_meta_function<add_pointer_t>(m_type<int>);
			assert_same_type(meta_f_result, m_type<int *>);
		}
	}
}