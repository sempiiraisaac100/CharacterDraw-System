<!DOCTYPE html>
<html>
<head>
    <meta charset="UTF-8">
    <title>{{ config('app.name') }}</title>
    <meta content='width=device-width, initial-scale=1, maximum-scale=1, user-scalable=no' name='viewport'>

   <!-- Tell the browser to be responsive to screen width -->
   <meta name="viewport" content="width=device-width, initial-scale=1">
   <!-- Font Awesome -->
   <link rel="stylesheet" href="{{URL::asset('assets/adminite/plugins/fontawesome-free/css/all.min.css')}}">
   {{-- <!-- Ionicons -->
   <link rel="stylesheet" href="https://code.ionicframework.com/ionicons/2.0.1/css/ionicons.min.css"> --}}
   <!-- Tempusdominus Bbootstrap 4 -->
   <link rel="stylesheet" href="{{URL::asset('assets/adminite/plugins/tempusdominus-bootstrap-4/css/tempusdominus-bootstrap-4.min.css')}}">
   <!-- iCheck -->
   <link rel="stylesheet" href="{{URL::asset('assets/adminite/plugins/icheck-bootstrap/icheck-bootstrap.min.css')}}">
   <!-- JQVMap -->
   <link rel="stylesheet" href="{{URL::asset('assets/adminite/plugins/jqvmap/jqvmap.min.css')}}">
   <!-- Theme style -->
   <link rel="stylesheet" href="{{URL::asset('assets/adminite/dist/css/adminlte.min.css')}}">
   <!-- overlayScrollbars -->
   <link rel="stylesheet" href="{{URL::asset('assets/adminite/plugins/overlayScrollbars/css/OverlayScrollbars.min.css')}}">
   <!-- Daterange picker -->
   <link rel="stylesheet" href="{{URL::asset('assets/adminite/plugins/daterangepicker/daterangepicker.css')}}">
   <!-- summernote -->
   <link rel="stylesheet" href="{{URL::asset('assets/adminite/plugins/summernote/summernote-bs4.css')}}">
   <!-- Toastr -->
   <link rel="stylesheet" href="{{URL::asset('assets/adminite/plugins/toastr/toastr.min.css')}}">
 
   {{-- <!-- Google Font: Source Sans Pro -->
   <link href="https://fonts.googleapis.com/css?family=Source+Sans+Pro:300,400,400i,700" rel="stylesheet"> --}}
  <!-- DataTables -->
  {{-- <link rel="stylesheet" type="text/css" href="https://cdn.datatables.net/v/dt/jszip-2.5.0/dt-1.11.3/b-2.0.1/b-html5-2.0.1/b-print-2.0.1/r-2.2.9/datatables.min.css"/> --}}
 
 
 
{{--  
   <link rel="apple-touch-icon" sizes="180x180" href="/favicon/apple-touch-icon.png">
   <link rel="icon" type="image/png" sizes="32x32" href="/favicon/favicon-32x32.png">
   <link rel="icon" type="image/png" sizes="16x16" href="/favicon/favicon-16x16.png">
   <link rel="manifest" href="/favicon/site.webmanifest"> --}}
   @yield('css')
   <style>
     /* Center the loader */
     #loader {
       position: absolute;
       left: 50%;
       top: 50%;
       z-index: 1;
       width: 120px;
       height: 120px;
       margin: -76px 0 0 -76px;
       border: 16px solid #f3f3f3;
       border-radius: 50%;
       border-top: 16px solid #3498db;
       -webkit-animation: spin 2s linear infinite;
       animation: spin 2s linear infinite;
     }
     
     @-webkit-keyframes spin {
       0% { -webkit-transform: rotate(0deg); }
       100% { -webkit-transform: rotate(360deg); }
     }
     
     @keyframes spin {
       0% { transform: rotate(0deg); }
       100% { transform: rotate(360deg); }
     }
     
     /* Add animation to "page content" */
     .animate-bottom {
       position: relative;
       -webkit-animation-name: animatebottom;
       -webkit-animation-duration: 1s;
       animation-name: animatebottom;
       animation-duration: 1s
     }
     
     @-webkit-keyframes animatebottom {
       from { bottom:-100px; opacity:0 } 
       to { bottom:0px; opacity:1 }
     }
     
     @keyframes animatebottom { 
       from{ bottom:-100px; opacity:0 } 
       to{ bottom:0; opacity:1 }
     }
     
     </style>
    @stack('third_party_stylesheets')

    @stack('page_css')
</head>

<body class="hold-transition sidebar-mini layout-fixed">
<div class="wrapper">
    <!-- Main Header -->
    <nav class="main-header navbar navbar-expand navbar-white navbar-light">
        <!-- Left navbar links -->
        <ul class="navbar-nav">
            <li class="nav-item">
                <a class="nav-link" data-widget="pushmenu" href="#" role="button"><i class="fas fa-bars"></i></a>
            </li>
        </ul>

        <ul class="navbar-nav ml-auto">
            <li class="nav-item dropdown user-menu">
                <a href="#" class="nav-link dropdown-toggle" data-toggle="dropdown">
                    {{-- <img src="https://assets.infyom.com/logo/blue_logo_150x150.png"
                         class="user-image img-circle elevation-2" alt="User Image"> --}}
                    <span class="d-none d-md-inline">{{ Auth::user()->name }}</span>
                </a>
                <ul class="dropdown-menu dropdown-menu-lg dropdown-menu-right">
                    <!-- User image -->
                    <li class="user-header bg-primary">
                        {{-- <img src="https://assets.infyom.com/logo/blue_logo_150x150.png"
                             class="img-circle elevation-2"
                             alt="User Image"> --}}
                        <p>
                            {{ Auth::user()->name }}
                            <small>Member since {{ Auth::user()->created_at->format('M. Y') }}</small>
                        </p>
                    </li>
                    <!-- Menu Footer-->
                    <li class="user-footer">
                        <a href="#" class="btn btn-default btn-flat">Profile</a>
                        <a href="#" class="btn btn-default btn-flat float-right"
                           onclick="event.preventDefault(); document.getElementById('logout-form').submit();">
                            Sign out
                        </a>
                        <form id="logout-form" action="{{ route('logout') }}" method="POST" class="d-none">
                            @csrf
                        </form>
                    </li>
                </ul>
            </li>
        </ul>
    </nav>

    <!-- Left side column. contains the logo and sidebar -->
@include('layouts.sidebar')

<!-- Content Wrapper. Contains page content -->
    <div class="content-wrapper">
        <section class="content">
            @yield('content')
        </section>
    </div>

    <!-- Main Footer -->
    <footer class="main-footer">
        <div class="float-right d-none d-sm-block">
            <b>Version</b> 3.1.0
        </div>
        <strong>
           Copyright &copy; 2022-2023 <a href="">KinderCare</a>.
        </strong>
        All rights reserved.
    </footer>
</div>
<script src="{{URL::asset('assets/adminite/plugins/jquery/jquery.min.js')}}"></script>

{{-- <!-- jQuery -->
<script src="{{URL::asset('assets/adminite/plugins/jquery/jquery.min.js')}}"></script> --}}
<!-- jQuery UI 1.11.4 -->
<script src="{{URL::asset('assets/adminite/plugins/jquery-ui/jquery-ui.min.js')}}"></script>
<!-- Resolve conflict in jQuery UI tooltip with Bootstrap tooltip -->
<script>
  $.widget.bridge('uibutton', $.ui.button)
</script>
{{-- <script src="https://cdnjs.cloudflare.com/ajax/libs/jquery/3.6.0/jquery.min.js"></script> --}}
<!-- Bootstrap 4 -->
<script src="{{URL::asset('assets/adminite/plugins/bootstrap/js/bootstrap.bundle.min.js')}}"></script>
<!-- Sparkline -->
<script src="{{URL::asset('assets/adminite/plugins/sparklines/sparkline.js')}}"></script>
<!-- JQVMap -->
<script src="{{URL::asset('assets/adminite/plugins/jqvmap/jquery.vmap.min.js')}}"></script>
<script src="{{URL::asset('assets/adminite/plugins/jqvmap/maps/jquery.vmap.usa.js')}}"></script>
<!-- jQuery Knob Chart -->
<script src="{{URL::asset('assets/adminite/plugins/jquery-knob/jquery.knob.min.js')}}"></script>
<!-- InputMask -->
<script src="{{URL::asset('assets/adminite/plugins/moment/moment.min.js')}}"></script>
<script src="{{URL::asset('assets/adminite/plugins/inputmask/min/jquery.inputmask.bundle.min.js')}}"></script>
<!-- daterangepicker -->
<script src="{{URL::asset('assets/adminite/plugins/moment/moment.min.js')}}"></script>
<script src="{{URL::asset('assets/adminite/plugins/daterangepicker/daterangepicker.js')}}"></script>
<!-- Tempusdominus Bootstrap 4 -->
<script src="{{URL::asset('assets/adminite/plugins/tempusdominus-bootstrap-4/js/tempusdominus-bootstrap-4.min.js')}}"></script>
<!-- Summernote -->
<script src="{{URL::asset('assets/adminite/plugins/summernote/summernote-bs4.min.js')}}"></script>
<!-- overlayScrollbars -->
<script src="{{URL::asset('assets/adminite/plugins/overlayScrollbars/js/jquery.overlayScrollbars.min.js')}}"></script>
<!-- AdminLTE App -->
<script src="{{URL::asset('assets/adminite/dist/js/adminlte.js')}}"></script>
<!-- AdminLTE dashboard demo (This is only for demo purposes) -->
<script src="{{URL::asset('assets/adminite/dist/js/pages/dashboard.js')}}"></script>
<!-- AdminLTE for demo purposes -->
<script src="{{URL::asset('assets/adminite/dist/js/demo.js')}}"></script>
<!-- DataTables -->
<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/pdfmake/0.1.36/pdfmake.min.js"></script>
<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/pdfmake/0.1.36/vfs_fonts.js"></script>
<script type="text/javascript" src="https://cdn.datatables.net/v/dt/jszip-2.5.0/dt-1.11.3/b-2.0.1/b-html5-2.0.1/b-print-2.0.1/r-2.2.9/datatables.min.js"></script>
<!-- Toastr -->
<script src="{{URL::asset('assets/adminite/plugins/toastr/toastr.min.js')}}"></script>

@stack('third_party_scripts')

@stack('page_scripts')
</body>
</html>
