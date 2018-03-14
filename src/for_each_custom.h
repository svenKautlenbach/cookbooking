#pragma once

#include <cassert>
#include <cstddef>

namespace recipe_1_09
{
	template<typename T, const size_t Size>
	class DummyCollection
	{
	public:

		DummyCollection(const std::initializer_list<T>& list)
		{
			assert(list.size() <= Size);
			std::copy(list.begin(), list.end(), m_data);
		}

		const T& getAt(const size_t index) const
		{
			throwIfIndexInvalid(index);

			return m_data[index];
		}

		void setAt(const size_t index, const T &value)
		{
			throwIfIndexInvalid(index);

			m_data[index] = value;
		}

		size_t getSize() const
		{
			return Size;
		}

	private:

		T m_data[Size] = {};

		void throwIfIndexInvalid(const size_t index) const
		{
			if (index >= Size)
				throw std::out_of_range("cant access element at this index " + std::to_string(index));
		}
	};

	template <typename T, typename C, const size_t Size>
	class DummyCollectionIterType
	{
	public:

		DummyCollectionIterType(C& collection, const size_t index) : m_index(index), m_collection(collection)
		{}

		bool operator!= (const DummyCollectionIterType& other) const
		{
			return m_index != other.m_index;
		}

		const T& operator* () const
		{
			return m_collection.getAt(m_index);
		}

		const DummyCollectionIterType& operator++ ()
		{
			++m_index;
			return *this;
		}

	private:

		size_t	m_index;
		C&		m_collection;
	};

	template <typename T, const size_t Size>
	using DummyCollectionIter = DummyCollectionIterType<T, DummyCollection<T, Size>, Size>;

	template <typename T, const size_t Size>
	using DummyCollectionConstIter = DummyCollectionIterType<T, const DummyCollection<T, Size>, Size>;

	template <typename T, const size_t Size>
	inline DummyCollectionIter<T, Size> begin(DummyCollection<T, Size>& collection)
	{
		return DummyCollectionIter<T, Size>(collection, 0);
	};

	template <typename T, const size_t Size>
	inline DummyCollectionIter<T, Size> end(DummyCollection<T, Size>& collection)
	{
		return DummyCollectionIter<T, Size>(collection, collection.getSize());
	};

	template <typename T, const size_t Size>
	inline DummyCollectionConstIter<T, Size> begin(const DummyCollection<T, Size>& collection)
	{
		return DummyCollectionConstIter<T, Size>(collection, 0);
	};

	template <typename T, const size_t Size>
	inline DummyCollectionConstIter<T, Size> end(const DummyCollection<T, Size>& collection)
	{
		return DummyCollectionConstIter<T, Size>(collection, collection.getSize());
	};

	void run()
	{
		DummyCollection<std::string, 5> a{"yo", "tere", "123", "78", "."};

		for (const auto& aa : a)
		{
			std::cout << aa << std::endl;
		}
	}
}