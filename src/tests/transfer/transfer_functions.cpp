#include "mpl.hpp"
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

        /* Create wrapper for std::integral_constant */
        template<std::size_t value>
        using constant_wrapper = std::integral_constant<std::size_t, value>;

		/* Test for type_wrapper<T> meta_container<f> and metafunction */
		void test::meta_function() {
			int *i{};
			assert_same_type(add_pointer_t::apply<int>::type{}, decltype(m_type<int *>)::type{});
			assert_same_type(add_pointer_t::apply<int>::type{}, i);
			auto meta_f_result = apply_meta_function<add_pointer_t>(m_type<int>);
			assert_same_type(meta_f_result, m_type<int *>);
			auto template_f_result = apply_template<mpl::list>(m_type<int>, m_type<char>, m_type<float>);
            assert_same_type(decltype(template_f_result)::type{}, mpl::list<int, char, float>{});
            using count_transfer = meta_container<mpl::count_transfer>;
            auto meta_f_count = apply_meta_function<count_transfer>(m_type<std::tuple<int, char, float>>, m_type<int>);
            assert_same_type(decltype(meta_f_count)::type{}, constant_wrapper<1>{});
            //auto meta_f_reverse = apply_meta_function<>()
		}
	}
}