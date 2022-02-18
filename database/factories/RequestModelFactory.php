<?php

namespace Database\Factories;

use App\Models\RequestModel;
use Illuminate\Database\Eloquent\Factories\Factory;

class RequestModelFactory extends Factory
{
    /**
     * The name of the factory's corresponding model.
     *
     * @var string
     */
    protected $model = RequestModel::class;

    /**
     * Define the model's default state.
     *
     * @return array
     */
    public function definition()
    {
        return [
            'pupil_id' => $this->faker->randomDigitNotNull,
        'assignment_id' => $this->faker->randomDigitNotNull,
        'message' => $this->faker->word,
        'deleted_at' => $this->faker->date('Y-m-d H:i:s'),
        'created_at' => $this->faker->date('Y-m-d H:i:s'),
        'updated_at' => $this->faker->date('Y-m-d H:i:s')
        ];
    }
}
