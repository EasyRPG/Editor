/*
 * This file is part of EasyRPG Editor.
 *
 * Originally from liblcf (https://github.com/EasyRPG/liblcf)
 * This license only applies to this file.
 *
 * This is Free/Libre Open Source Software, released under the MIT License.
 */

#pragma once
#include <utility>

template <typename F>
class ScopeGuard {
	public:
		ScopeGuard() = default;
		explicit ScopeGuard(const F& f) : _f(f), _active(true) {}
		explicit ScopeGuard(F&& f) : _f(std::move(f)), _active(true) {}

		ScopeGuard(const ScopeGuard&) = delete;
		ScopeGuard& operator=(const ScopeGuard&) = delete;

		ScopeGuard(ScopeGuard&& o)
			: _f(std::move(o._f)), _active(true) { o._active = false; }
		ScopeGuard& operator=(ScopeGuard&&) = delete;

		~ScopeGuard() { Fire(); }

		void Fire() noexcept;
		void Dismiss() noexcept;
		bool IsActive() noexcept;
	private:
		F _f;
		bool _active = false;
};

template <typename F>
inline ScopeGuard<F> makeScopeGuard(F&& f) {
	return ScopeGuard<F>(std::forward<F>(f));
}

template <typename F>
inline void ScopeGuard<F>::Fire() noexcept {
	if (_active) {
		_f();
		Dismiss();
	}
}

template <typename F>
inline void ScopeGuard<F>::Dismiss() noexcept {
	_active = false;
}

template <typename F>
inline bool ScopeGuard<F>::IsActive() noexcept {
	return _active;
}
