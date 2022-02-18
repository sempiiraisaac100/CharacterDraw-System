<li class="nav-item">
    <a href="{{ url('/') }}" class="nav-link">
        <p>Dashboard</p>
    </a>
</li>
@if(Auth::user()->email == "admin@kindercare.com")
<li class="nav-item">
    <a href="{{ route('teachers.index') }}"
       class="nav-link {{ Request::is('teachers*') ? 'active' : '' }}">
        <p>Teachers</p>
    </a>
</li>
@endif

<li class="nav-item">
    <a href="{{ route('pupils.index') }}"
       class="nav-link {{ Request::is('pupils*') ? 'active' : '' }}">
        <p>Pupils</p>
    </a>
</li>


<li class="nav-item">
    <a href="{{ route('assignments.index') }}"
       class="nav-link {{ Request::is('assignments*') ? 'active' : '' }}">
        <p>Assignments</p>
    </a>
</li>


<li class="nav-item">
    <a href="{{ route('attempts.index') }}"
       class="nav-link {{ Request::is('attempts*') ? 'active' : '' }}">
        <p>Attempts</p>
    </a>
</li>


<li class="nav-item">
    <a href="{{ route('requestModels.index') }}"
       class="nav-link {{ Request::is('requestModels*') ? 'active' : '' }}">
        <p>Requests</p>
    </a>
</li>


<li class="nav-item">
    <a href="{{ url('changepassword') }}"
       class="nav-link">
        <p>Change Password</p>
    </a>
</li>