<?php

namespace App\Models;

use Eloquent as Model;
use Illuminate\Database\Eloquent\SoftDeletes;
use Illuminate\Database\Eloquent\Factories\HasFactory;

/**
 * Class RequestModel
 * @package App\Models
 * @version February 18, 2022, 12:34 pm UTC
 *
 * @property integer $pupil_id
 * @property integer $assignment_id
 * @property string $message
 */
class RequestModel extends Model
{
    use SoftDeletes;

    use HasFactory;

    public $table = 'requests';
    
    const CREATED_AT = 'created_at';
    const UPDATED_AT = 'updated_at';


    protected $dates = ['deleted_at'];



    public $fillable = [
        'pupil_id',
        'assignment_id',
        'message'
    ];

    /**
     * The attributes that should be casted to native types.
     *
     * @var array
     */
    protected $casts = [
        'id' => 'integer',
        'pupil_id' => 'integer',
        'assignment_id' => 'integer',
        'message' => 'string'
    ];

    /**
     * Validation rules
     *
     * @var array
     */
    public static $rules = [
        'pupil_id' => 'required|integer',
        'assignment_id' => 'required|integer',
        'message' => 'required|string|max:255',
        'deleted_at' => 'nullable',
        'created_at' => 'nullable',
        'updated_at' => 'nullable'
    ];

    
}
