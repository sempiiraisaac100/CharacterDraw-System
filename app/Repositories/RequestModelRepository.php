<?php

namespace App\Repositories;

use App\Models\RequestModel;
use App\Repositories\BaseRepository;

/**
 * Class RequestModelRepository
 * @package App\Repositories
 * @version February 18, 2022, 12:34 pm UTC
*/

class RequestModelRepository extends BaseRepository
{
    /**
     * @var array
     */
    protected $fieldSearchable = [
        'pupil_id',
        'assignment_id',
        'message'
    ];

    /**
     * Return searchable fields
     *
     * @return array
     */
    public function getFieldsSearchable()
    {
        return $this->fieldSearchable;
    }

    /**
     * Configure the Model
     **/
    public function model()
    {
        return RequestModel::class;
    }
}
