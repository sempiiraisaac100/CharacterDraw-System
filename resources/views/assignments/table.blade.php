<div class="table-responsive">
    <table class="table" id="assignments-table">
        <thead>
        <tr>
            <th>Assignment ID</th>
            <th>Characters</th>
        <th>Expiry Date</th>
        <th>Attempt Status</th>
        <th>Activation Status</th>
            <th>Action</th>
        </tr>
        </thead>
        <tbody>
        @foreach($assignments as $assignment)
            <tr>
                <td>{{ $assignment->id }}</td>
                <td>{{ $assignment->characters }}</td>
            <td>{{ $assignment->expiry_date }}</td>
            <td>{{ $assignment->attempt_status }}</td>
            <td>{{ $assignment->activation_status }}</td>
                <td width="120">
                    {!! Form::open(['route' => ['assignments.destroy', $assignment->id], 'method' => 'delete']) !!}
                    <div class='btn-group'>
                        <a href="{{ route('assignments.show', [$assignment->id]) }}"
                           class='btn btn-default btn-xs'>
                            <i class="far fa-eye"></i>
                        </a>
                        <a href="{{ route('assignments.edit', [$assignment->id]) }}"
                           class='btn btn-default btn-xs'>
                            <i class="far fa-edit"></i>
                        </a>
                        {!! Form::button('<i class="far fa-trash-alt"></i>', ['type' => 'submit', 'class' => 'btn btn-danger btn-xs', 'onclick' => "return confirm('Are you sure?')"]) !!}
                    </div>
                    {!! Form::close() !!}
                </td>
            </tr>
        @endforeach
        </tbody>
    </table>
</div>
@push('third_party_stylesheets')
{{-- <link rel="stylesheet" type="text/css" href="https://cdn.datatables.net/1.11.4/css/jquery.dataTables.css"> --}}
<link rel="stylesheet" type="text/css" href="https://cdn.datatables.net/v/dt/jszip-2.5.0/dt-1.11.4/b-2.2.2/b-colvis-2.2.2/b-html5-2.2.2/b-print-2.2.2/sc-2.0.5/datatables.min.css"/>

     <!-- DataTables -->
  {{-- <link rel="stylesheet" href="{{URL::asset('assets/adminite/plugins/datatables-bs4/css/dataTables.bootstrap4.min.css')}}">
  <link rel="stylesheet" href="{{URL::asset('assets/adminite/plugins/datatables-responsive/css/responsive.bootstrap4.min.css')}}"> --}}
@endpush
@push('third_party_scripts')
 
<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/pdfmake/0.1.36/pdfmake.min.js"></script>
<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/pdfmake/0.1.36/vfs_fonts.js"></script>
<script type="text/javascript" src="https://cdn.datatables.net/v/dt/jszip-2.5.0/dt-1.11.4/b-2.2.2/b-colvis-2.2.2/b-html5-2.2.2/b-print-2.2.2/sc-2.0.5/datatables.min.js"></script>
@endpush
@push('page_scripts')
    <script>
         $(function () {
            $('#assignments-table').DataTable({
                  'destroy': false,
                  dom: 'Bfrtip',
                  buttons: [
                        {
                    extend: 'copyHtml5',
                    exportOptions: {
                        columns: [ 0,1, 2, 3,4]
                    }   
                },
                {
                    extend: 'excelHtml5',
                    exportOptions: {
                        columns: [0,1, 2, 3,4]
                    }
                },
                {
                    extend: 'pdfHtml5',
                    exportOptions: {
                        columns: [ 0, 1, 2, 3,4]
                    }
                },
                {
                    extend: 'csvHtml5',
                    exportOptions: {
                        columns: [ 0, 1, 2, 3 ,4]
                    }
                },
                  ]
              });
        });
    </script>
@endpush
