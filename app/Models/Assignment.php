<?php

namespace App\Models;

use Eloquent as Model;
use Illuminate\Database\Eloquent\SoftDeletes;
use Illuminate\Database\Eloquent\Factories\HasFactory;

/**
 * Class Assignment
 * @package App\Models
 * @version February 18, 2022, 11:52 am UTC
 *
 * @property string $characters
 * @property string $expiry_date
 * @property string $attempt_status
 * @property string $activation_status
 */
class Assignment extends Model
{
    use SoftDeletes;

    use HasFactory;

    public $table = 'assignments';
    
    const CREATED_AT = 'created_at';
    const UPDATED_AT = 'updated_at';


    protected $dates = ['deleted_at'];



    public $fillable = [
        'characters',
        'expiry_date',
        'attempt_status',
        'activation_status'
    ];

    /**
     * The attributes that should be casted to native types.
     *
     * @var array
     */
    protected $casts = [
        'id' => 'integer',
        'characters' => 'string',
        'expiry_date' => 'date',
        'attempt_status' => 'string',
        'activation_status' => 'string'
    ];

    /**
     * Validation rules
     *
     * @var array
     */
    public static $rules = [
        'characters' => 'required|string|max:8',
        'expiry_date' => 'required',
        'activation_status' => 'required|string|max:255',
        'created_at' => 'nullable',
        'updated_at' => 'nullable'
    ];

    
}
