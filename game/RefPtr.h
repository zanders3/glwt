#pragma once

template <typename T> class RefPtr
{
public:
	RefPtr() : m_ptr(0), m_count(0)
	{}

	RefPtr(T* ptr) : m_ptr(ptr), m_count(new int(1))
	{}

	~RefPtr()
	{
		if (m_count)
		{
			--(*m_count);
			if (*m_count == 0)
				delete m_ptr;
		}
	}

	RefPtr(const RefPtr<T>& other) : m_ptr(0), m_count(0)
	{
		*this = other;
	}

	void operator =(const RefPtr<T>& other)
	{
		if (m_count)
		{
			--(*m_count);
			if (*m_count == 0)
				delete m_ptr;
		}

		m_count = other.m_count;
		m_ptr = other.m_ptr;

		if (other.m_count)
		{
			++(*other.m_count);
		}
	}

	bool valid() const
	{
		return m_ptr != 0;
	}

	T* get()
	{
		return m_ptr;
	}

	T& operator *()
	{
		return *m_ptr;
	}

	T* operator->()
	{
		return m_ptr;
	}
private:
	T* m_ptr;
	int* m_count;
};
